#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
char s[1000005],t[1000005];
queue <int> Q;
int n;
bool check()
{
	for(int i=1;i<=n;i++)if(s[i]!=t[i])return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	if(check()){printf("0\n");return 0;}
	int head=1,tail=0;
	int posi=n;
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		if(t[i]==t[i-1])continue;
		posi=min(posi,i);
		while(posi&&t[i]!=s[posi])posi--;
		if(!posi){printf("-1\n");return 0;}
		while(!Q.empty())
		{
			if((int)Q.front()-(int)Q.size()>=i)Q.pop();
			else break;
		}
		Q.push(posi);
		if(i!=posi)ans=max(ans,(int)Q.size());
	}
	printf("%d\n",ans+1);
	return 0;
}