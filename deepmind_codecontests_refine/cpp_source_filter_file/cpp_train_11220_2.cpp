#include <bits/stdc++.h> 
using namespace std; 
int main()
{
	int a;
	long long b[100001],cnt=1;
	cin>>a;
	for (int i=0;i<a;i++)
	{
		cin>>b[i];
		if (b[i]==0)
		{
			cout<<"0";
			return 0;
		}
	}
	for (int i=0;i<a;i++)
	{
		if (a[i]<=1000000000000000000/cnt)
			cnt*=b[i];
		else
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<cnt;
	return 0;
}
