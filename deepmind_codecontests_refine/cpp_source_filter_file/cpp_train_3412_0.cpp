#include <bits/stdc++.h>
using namespace std;

int main() {
	int k;
	cin >> k;
	int c=1,a=7%k;
	while(a!=0)
	{
		c++;
		int b=(a*10)+a;
		a=b%k
		if(c==pow(10,7))
		{
			c=-1;
			break;
		}
	}
	cout << c << endl;
	return 0;
}
