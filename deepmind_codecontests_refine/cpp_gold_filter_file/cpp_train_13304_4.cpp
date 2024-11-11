#include<bits/stdc++.h>
using namespace std;
long long l,r;

int main()
{
	cin>>l>>r;
	if((r/2019-l/2019)>0)
		cout<<0<<endl;
	else
	{
		long long ans=2020;
		for(long long i=l;i<=r;i++)
		{
			for(long long j=i+1;j<=r;j++)
			{
				ans=min(ans,(i*j%2019));
			}
		}
		cout<<ans<<endl;
	}
}