#ifndef _DataCore_NeuralHuge_h_
#define _DataCore_NeuralHuge_h_

#include "Slot.h"
#include "SimBroker.h"

namespace DataCore {
using namespace Narx;

/*
	Huge agents allows multiple actions for different symbols until wait action is given.
	These are too slow to process with current computers.
	To avoid getting stuck with this, "agents of agents" or "double agents" was introduced.
	This was still good exercise for the programmer and some common problems were solved.
*/

class HugeDQNAgent : public Slot {
	
	ConvNet::DQNAgent agent;
	SimBroker broker;
	double reward;
	Vector<int> velocity;
	int action, prev_action;
	int actions_total;
	int max_velocity;
	
	SlotPtr src;
	Vector<double> input_array;
	int sym_count, tf_count;
	int max_shift, total;
	bool do_training;
	
	void Forward(const SlotProcessAttributes& attr);
	void Backward(const SlotProcessAttributes& attr);
public:
	HugeDQNAgent();
	virtual void SetArguments(const VectorMap<String, Value>& args);
	virtual void Init();
	virtual bool Process(const SlotProcessAttributes& attr);
	virtual String GetKey() const {return "hugedqn";}
	virtual String GetName() {return "Huge DQN-Agent";}
};



class HugeMonaAgent : public Slot {
	
	Mona agent;
	SimBroker broker;
	Vector<int> velocity;
	double CHEESE_NEED, CHEESE_GOAL;
	double reward;
	int action, prev_action;
	int actions_total;
	int max_velocity;
	
	SlotPtr src;
	Vector<double> input_array;
	int sym_count, tf_count;
	int max_shift, total;
	bool do_training;
	
	void Forward(const SlotProcessAttributes& attr);
	void Backward(const SlotProcessAttributes& attr);
public:
	HugeMonaAgent();
	virtual void SetArguments(const VectorMap<String, Value>& args);
	virtual void Init();
	virtual bool Process(const SlotProcessAttributes& attr);
	virtual String GetKey() const {return "hugemona";}
	virtual String GetName() {return "Huge Mona-Agent";}
};


}

#endif
