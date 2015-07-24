	


#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>



	srand(0);
	list<int> l = {5,4,3,2,1,10,20,100,300,30,21,59,54,25,95,78,53,235,542,125,82,29,762,241,834};
	for (size_t i = 0; i < 1000; i++)
	{
		l.push_back(rand()%1000);
	}
	list<int> carry;
	list<int> counter[64];
	int fill = 0;
	while (!l.empty())
	{
		carry.splice(carry.begin(), l, l.begin());
		int i = 0;
		while (i<fill&&!counter[i].empty())
		{
			counter[i].merge(carry);
			carry.swap(counter[i++]);
		}
		carry.swap(counter[i]);
		if (i==fill)
		{
			++fill;
		}
	}

	for (size_t i = 1; i < fill; i++)
	{
		counter[i].merge(counter[i - 1]);

	}
	l.swap(counter[fill - 1]);

	for (auto item : l)
		cout << item << " ";
	cout << endl;
 