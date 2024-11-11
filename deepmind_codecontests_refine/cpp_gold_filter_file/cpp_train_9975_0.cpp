#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
const int inf=0x3f3f3f3f;
inline int read(){
	char c=getchar();int t=0,f=1;
	while((!isdigit(c))&&(c!=EOF)){if(c=='-')f=-1;c=getchar();}
	while((isdigit(c))&&(c!=EOF)){t=(t<<3)+(t<<1)+(c^48);c=getchar();}
	return t*f;
}
int n,s,t;
struct edge{
	int v,p,w;
}e[maxn<<1];
int h[maxn],cnt=1;
inline void add(int a,int b,int c){
	e[++cnt].p=h[a];
	e[cnt].v=b;
	e[cnt].w=c;
	h[a]=cnt;
}
int dis[maxn];
bool bfs(){
	queue<int> q;
	while(!q.empty())q.pop();
	q.push(s);
	memset(dis,0,sizeof(dis));
	dis[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=h[u];i;i=e[i].p){
			int v=e[i].v;
			if(e[i].w&&!dis[v]){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[t];
}
int ht[maxn];
int dfs(int u,int rest){
	if((u==t)||rest==0)return rest;
	int tot=0;
	for(int &i=ht[u];i;i=e[i].p){
		int v=e[i].v;
		if(e[i].w&&dis[v]==dis[u]+1){
			int di=dfs(v,min(rest,e[i].w));
			e[i].w-=di;e[i^1].w+=di;
			rest-=di;tot+=di;
			if(rest==0)break;
		}
	}
	return tot;
}
int dinic(){
	int ans=0;
	while(bfs()){
		int di=0;
		for(int i=s;i<=t;i++)ht[i]=h[i];
		while(di=dfs(s,inf))ans+=di;
	}
	return ans;
}
int cho[maxn];
vector<int> g[maxn];
typedef pair<int,int> pii;
pii res[maxn];
bool get(){
	for(int u=1;u<n;u++){
		for(int i=h[u];i;i=e[i].p){
			int v=e[i].v;
			if(v!=s&&(e[i].w==0)){cho[v-n]=u;}
		}
	}
	queue<int> q;
	while(!q.empty())q.pop();
	q.push(n);int sum=0;
	while(!q.empty()){
		int u=q.front();q.pop();sum++;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(cho[v])res[v]=pii(u,cho[v]),q.push(cho[v]),cho[v]=0;
		}
	}
	return sum==n;
}
signed main(){
	n=read();s=0,t=n+n;
	for(int i=1;i<n;i++){
		int k=read();
		for(int j=1;j<=k;j++){
			int x=read();
			if(x!=n){
			add(x,i+n,1);
			add(i+n,x,0);
			}
			g[x].push_back(i);
		}
		add(s,i,1);
		add(i,s,0);
		add(i+n,t,1);
		add(t,i+n,0);
	}
	if(dinic()<n-1){puts("-1");return 0;}
	if(!get()){puts("-1");return 0;}
	for(int i=1;i<n;i++)
	printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}
