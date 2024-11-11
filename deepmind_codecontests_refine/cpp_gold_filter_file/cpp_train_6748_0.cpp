#include<cstdio>
inline void read(int&r)
{
	register char c;r=0;
	do c=getchar();while(c<'0'||c>'9');
	do r=r*10+c-'0',c=getchar();while(c>='0'&&c<='9');
}

char s[200001];
int first[200001];
int a[200001],b[200001],q[400001];
struct ac{ int to,nx; }e[400001];
void readedge()
{
	static int L=1,u,v;read(u),read(v);
	e[L].to=v,e[L].nx=first[u],first[u]=L++;
	e[L].to=u,e[L].nx=first[v],first[v]=L++;
	(s[u]=='A'?a:b)[v]++;
	(s[v]=='A'?a:b)[u]++;
}

int main()
{
	int n,u,t=0,i,j;
	scanf("%d%d%s",&n,&t,s+1);
	while(t--)readedge();
	for(u=1,t=0;u<=n;u++)if(!a[u]||!b[u])q[t++]=u;
	for(i=0;i<t;i++)
		for(j=first[u=q[i]];j;j=e[j].nx)
			if(!--(s[u]=='A'?a:b)[e[j].to]&&(s[u]=='A'?b:a)[e[j].to])
				q[t++]=e[j].to;
	puts(t==n?"No":"Yes");
}