#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	cin>>a;
	long long b=100,c=0;
	while(b<a)
	{
		b+=P/100;
		c++;
	}
	cout<<c<<endl;
 	return 0;
}