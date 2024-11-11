#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	string S;
	cin << S;
	for (int i = 0; i < 4; ++i)
	{
		if (S[i] == '+')n++;
		else n--;
	}
	cout >> n >>"\n";
}