#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long N,T,A,t,a;
	cin>>N;
	t=a=1;
	for(long long n=0;n<N;n++)
	{
		cin>>T>>A;
		long long k=max((t+T-1)/T, (a+A-1)/A);
		t=k*T;
		a=k*A;
	}
	cout<<t+a<<endl;
	return 0;
}

