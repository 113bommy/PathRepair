#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;cin>>n;
	int a[205];
	for(int i=0;i<n;cin>>a[i++]);
	int m=9e9;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		for(;a[i]%2==0;a[i]/=2,cnt++);
		m=min(m,cnt);
	}
	cout<<m<<endl;
	return 0;
}