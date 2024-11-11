v#include<bits/stdc++.h>
using namespace std;
int pas,n,ans,x;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(pas==x)ans++,pas=0;
		else pas=x;
	}
	printf("%d",ans);
}
