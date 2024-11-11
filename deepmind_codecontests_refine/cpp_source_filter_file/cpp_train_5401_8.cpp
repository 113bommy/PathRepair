#include <iostream>
using namespace std;
bool t[10000] = {false};
int main()
{
	int n, i;
	t[0] = true;
	for (i = 2; i * i <= 10000; i++)
	{
		if (!t[i-1])
		{
			for (j = i+i; j <= 10000; j+=i)
				t[j-1] = true;
		}
	}
	while (cin >> n, n)
	{
		for (i = n; i >= 5; i--)
		{
			if ((!t[i-1]) && (!t[i-3]))
			{
				cout << i-2 << " " << i << endl;
				break;
			}
		}
	}
}