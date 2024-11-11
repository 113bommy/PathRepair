#include<bits/stdc++.h>
using namespace std;

const int N=201000;

int n,a[N],f[N],index[N];
int ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{	
		scanf("%d",a+i);
		index[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=f[index[a[i]-1]]+1;
		ans=max(ans,f[i]);
	}
	cout<<n-ans<<endl;
	return 0;
}