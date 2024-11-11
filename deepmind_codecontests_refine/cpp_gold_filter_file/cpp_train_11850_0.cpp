#include<iostream>
using namespace std;
long n,m,ans;
int main()
{
	cin>>n>>m;
	for(long i=1;i*i<=m;i++)
	{
		if(m%i)continue;
		if(m/i>=n)ans=ans<i?i:ans;
		if(i>=n)ans=ans<m/i?m/i:ans;
	}
	cout<<ans<<endl;
}
