#include<iostream>
using namespace std;
long n,m,ans=1;
main()
{
	cin>>n>>m;
	for(long i=2;i*i<=m;i++)
	{
		if(m%i)continue;
		if(m/i>=n)ans=ans<i?i:ans;
		if(i>=n)ans=ans<m/i?m/i:ans;
	}
	cout<<ans<<endl;
}
