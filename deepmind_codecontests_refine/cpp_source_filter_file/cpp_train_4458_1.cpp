#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double s,ans=0;
	char c[5];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %s",&s,c);
		if(c[0]=='J')
			ans+=s;
		else
			ans+=s*380000
	}
	printf("%.5lf",ans);
	return 0;
}