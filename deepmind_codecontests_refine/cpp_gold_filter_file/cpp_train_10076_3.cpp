#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,ans=0,a,mi=1e9;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		if(a<mi)mi=a,ans++;
	}
	cout<<ans<<endl;
}