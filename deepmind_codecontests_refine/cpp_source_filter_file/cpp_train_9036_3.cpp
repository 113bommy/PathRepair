#include<bits/stdc++.h>
using namespace std;
char s[200005];
int n,x
long long ans;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='W')
		{
			x++;
			ans+=i-x;
		}
	printf("%lld",ans);
}