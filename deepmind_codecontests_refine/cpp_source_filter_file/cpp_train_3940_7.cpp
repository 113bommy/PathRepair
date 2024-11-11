#include<bits/std++.h>
using namespace std;
int n,k,ans=1;
int main()
{
	cin>>n>>k;
	for(int i=0; i<n; i++)
	{
		if(ans>k)
		ans+=k;
		else
		ans*=2;
	}
	cout<<ans;
}