#include<bits/stdc++.h>
using namespace std;
long long n1,n2=100005;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		long long a,b;
		cin>>a>>b;
		if(a>n1)
		  n1=a;
		if(b<n2)
		  n2=b;
	}
	cout<<max(n2-n1+1,0);
	return 0;
}
