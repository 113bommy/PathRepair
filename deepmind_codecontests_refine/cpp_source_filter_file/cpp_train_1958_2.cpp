#include <bits/stdc++.h>
using namespace std;
struct E{
	int to;
	int clr;
	int len;
};
vector<E> g[100005];
int anc[18][100005],d[100005];
void dfs(int u,int fa){
	for(auto v:g[u]){
		if(v.to==fa){
			continue;
		}
		anc[0][v.to]=u;
		d[v.to]=d[u]+1;
		dfs(v.to,u);
	}
}
int LCA(int x,int y){
	if(d[x]>d[y]){
		swap(x,y);
	}
	for(int ind=0;d[x]<d[y];++ind){
		if((d[y]-d[x])>>ind&1){
			y=anc[ind][y];
		}
	}
	if(x==y){
		return x;
	}
	for(int ind=18;ind--;){
		if(anc[ind][x]!=anc[ind][y]){
			x=anc[ind][x],y=anc[ind][y];
		}
	}
	return anc[0][x];
}
struct info{
	int ind;
	char typ;
	int clr;
	int cnt;
	info(){}
	info(int in,char ty,int cl,int cn){
		ind=in,typ=ty,clr=cl,cnt=cn;
	}
}; 
vector<info> q[100005];
int sum[100005];
int cnt[100005];
int ans[100005];
void DFS(int u,int fa,ll len){
	for(auto now:q[u]){
		if(now.typ=='d'){
			ans[now.ind]+=len*now.cnt;
		}
		else if(now.typ=='s'){
			ans[now.ind]+=sum[now.clr]*now.cnt;
		}
		else{
			ans[now.ind]+=cnt[now.clr]*now.cnt;
		}
	}
	for(auto v:g[u]){
		if(v.to==fa){
			continue;
		}
		sum[v.clr]+=v.len;
		cnt[v.clr]++;
		DFS(v.to,u,len+v.len);
		sum[v.clr]-=v.len;
		cnt[v.clr]--;
	}
}
int main(){
	int n,Q;
	cin>>n>>Q;
	for(int i=1;i<n;++i){
		int u,v,clr,leng;
		cin>>u>>v>>clr>>leng; 
		u--,v--,clr--;
		E a;
		a.to=v,a.len=leng,a.clr=clr;
		E b;
		b.to=u,b.len=leng,b.clr=clr;
		g[u].push_back(a),g[v].push_back(b);
	}
	dfs(0,0);
	for(int ind=0;ind<17;++ind){
		for(int u=0;u<n;++u){
			anc[ind+1][u]=anc[ind][anc[ind][u]];
		}
	}
	for(int i=0;i<Q;++i){
		int clr,leng,u,v;
		cin>>clr>>leng>>u>>v;
		clr--;
		u--;
		v--;
		int lca=LCA(u,v);
		q[u].emplace_back(i,'d',0,1);
		q[u].emplace_back(i,'s',clr,-1);
		q[u].emplace_back(i,'c',clr,leng);
		q[v].emplace_back(i,'d',0,1);
		q[v].emplace_back(i,'s',clr,-1);
		q[v].emplace_back(i,'c',clr,leng);
		q[lca].emplace_back(i,'d',0,-2);
		q[lca].emplace_back(i,'s',clr,2);
		q[lca].emplace_back(i,'c',clr,-2*leng);
	}
	DFS(0,0,0);
	for(int i=0;i<Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
