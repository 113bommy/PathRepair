#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int sum = 0; max = 0, tmp;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		sum += tmp;
		if (tmp > max) max = tmp;
	}
	
	cout << sum - max / 2;
}