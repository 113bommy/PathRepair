#include<bits/stdc++.h>
using namespace std;
#define MN 105
#define inf 0x7f7f7f7f
int fr[MN],nex[MN*MN],vi[MN*MN],wi[MN*MN],tot=0,pi[MN*MN];
void Add(int x,int y,int z){
	vi[++tot]=y;wi[tot]=z;nex[tot]=fr[x];fr[x]=tot;
	vi[++tot]=x;wi[tot]=0;nex[tot]=fr[y];fr[y]=tot;
}
int v[MN],n;
int cur[MN],dep[MN],s,t,xr[MN];
void init(){
	++xr[dep[t]=1];
	queue<int> Q;Q.push(t);
	while(!Q.empty()){
		int x=Q.front();Q.pop();
		for(int i=fr[x];i;i=nex[i])if(!dep[vi[i]]){
			++xr[dep[vi[i]]=dep[x]+1];
			Q.push(vi[i]);
		}
	}
	for(int i=0;i<=n+1;++i)cur[i]=fr[i];
}
long long dfs(int x,int f){
	if(x==t||f==0)return f;
	int flow=0,fl;
	for(int &i=cur[x];i;i=nex[i]){
		if(dep[x]==dep[vi[i]]+1&&(fl=dfs(vi[i],min(f,wi[i])))>0){
			f-=fl;flow+=fl;wi[i]-=fl;wi[(i&1)?(i+1):(i-1)]+=fl;if(!f)return flow;
		}
	}
	if(!(--xr[dep[x]]))dep[s]=n+3;
	else ++xr[++dep[x]],cur[x]=fr[x];
	return flow;
}
int main(){
	long long sum=0;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",v+i);
	for(int i=1;i<=n;++i){
		if(v[i]>=0)add(i,n+1,v[i]),sum+=v[i];
		else add(0,i,-v[i]);
		for(int j=2;j*i<=n;++j){
			add(i,j*i,inf);
		}
	}
	s=0;t=n+1;init();
	while(dep[s]<=n+2)sum-=dfs(s,inf);
	cout<<sum;
	return 0;
}