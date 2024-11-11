#include<bits/stdc++.h>
using namespace std;
long long i=0,k,n;
int main()
{
	cin>>k;
	while(i<100000a0)
	{
		i++;
		n=(n*10+7)%k;
		if(n==0)
		{
			cout<<i;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}