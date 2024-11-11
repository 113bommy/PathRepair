#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int a = 0, b = 0;
	int c[100];
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= b; i++)
	{
		for (int j = 0; j < (a - 1); j++)
		{
			if ((c[j] % i)>(c[j + 1] % i))
			{
				int k = c[j];
				c[j] = c[j + 1];
				c[j + 1] = k;
			}
		}
	}
	for (int i = 0; i < a; i++)
	{
		cout << c[i] << endl;
	}

	gereturn 0;
}