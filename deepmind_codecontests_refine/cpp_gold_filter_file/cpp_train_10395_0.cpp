#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N=3e2+5;
const ll inf=2e15;
const ll mod=1e9+7;
//题意:n*m地图 n,m<=100,起点S,终点T 'o'表示叶子,每次可以跳到同行或者同列的'o'上,问最少删掉多少个'o'使得S无法到达T? 
//最小割模型,先把图变为二分图,每行每列加上源点和汇点,两边点分别为1~n,1~m
//对叶子'o'(x,y):x-y连接一条边 表示第x行的叶子可以跳到第y列 容量为1:表示删除(x,y)这一个点 
//加上边 S->SX S-SY TX->T,TY->T 容量为inf 不能删除
//现在只要求出从S->T的最大流即可,因为最大流时的图,无增广路即,S->T不存在路径,对应的s-t割为最小割,容量最小. 

char s[N][N]; 
ll n,m,g[N][N];
ll path[N],flow[N],start,End;
queue<int> q;
void init()
{
	memset(g,0,sizeof(g));	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='S')
			{
				g[0][i]=inf;
				g[0][n+j]=inf;	
			}
			if(s[i][j]=='T')
			{
				g[i][n+m+1]=inf;
				g[n+j][n+m+1]=inf;
			}
			if(s[i][j]=='o')
				g[i][n+j]=1,g[n+j][i]=1;
		}
	}
}

ll bfs()
{
	while(!q.empty())
		q.pop();
	memset(path,-1,sizeof(path));
	path[start]=0,flow[start]=inf;
	q.push(start);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(t==End)
			break;
		for(int i=1;i<=n+m+1;i++)
		{
			if(i!=start && path[i]==-1 && g[t][i])
			{
				flow[i]=min(flow[t],g[t][i]);
				q.push(i);
				path[i]=t;
			}
		}
	}
	if(path[End]==-1)	
		return -1;
	return flow[End];
}
ll Edmonds_Karp()
{
	ll mx_flow=0,step,now,pre;
	while((step=bfs())!=-1)//找不到增广路退出 
	{
		mx_flow+=step;
		now=End;
		while(now!=start)
		{
			pre=path[now];
			g[pre][now]-=step;//更新正向边容量
			g[now][pre]+=step;//更新反向边(Gf走反向边 相当于在G中减小该边流量) 
			now=pre;
		}
	}
	return mx_flow;	
} 
int main()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		init();//建图 
		start=0,End=n+m+1;
		ll ans=Edmonds_Karp();
		if(ans>=inf)
			puts("-1");
		else
			cout<<ans<<endl;
	}
	return 0;
}