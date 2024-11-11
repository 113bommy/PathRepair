#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int MAX_M=100000,MAX_N=100000,MAX_K=200000;

struct P{
	int x,y;
	int index;
};

bool comp(const P &a,const P &b){
	if (a.y!=b.y){
		return a.y<b.y;
	}
	return a.x<b.x;
}

bool comp2(const P &a,const P &b){
	if (a.x!=b.x){
		return a.x<b.x;
	}
	return a.y<b.y;
}

int M,N,K;
P p[MAX_K+2];

struct edge{
	int to,cost;
};

typedef pair<long long,int> PA;

const long long INF=1000000000000000;

int V;
vector<edge> G[MAX_K*2+4];

long long d[MAX_K*2+4];

long long dijkstra(){
	priority_queue<PA,vector<PA>,greater<PA> > que;
	fill(d,d+V,INF);
	d[K+2]=0;
	que.push(PA(0,K+2));
	while(!que.empty()){
		PA pa=que.top();
		que.pop();
		int v=pa.second,dis=pa.first;
		if (dis>d[v]) continue;
		for (int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if (d[v]+e.cost<d[e.to]){
				d[e.to]=d[v]+e.cost;
				que.push(PA(d[e.to],e.to));
			}
		}
	}
	return min(d[K+1],d[2*K+3]);
}

int main(){
	scanf("%d %d %d",&M,&N,&K);
	for (int i=0;i<K;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p[i+1].x=x;
		p[i+1].y=y;
		p[i+1].index=i+1;
	}
	p[0].x=1;	//スタート
	p[0].y=1;
	p[0].index=0;
	p[K+1].x=M;	//ゴール
	p[K+1].y=N;
	p[K+1].index=K+1;
	V=K*2+4;	//頂点の個数
	//辺を張る
	sort(p,p+K+2,comp);	//横の辺を張る
	for (int i=0;i<K+1;i++){
		if (p[i].y==p[i+1].y){
			int cost=p[i+1].x-p[i].x;
			edge e{p[i+1].index,cost};
			G[p[i].index].push_back(e);
			e.to=p[i].index;
			G[p[i+1].index].push_back(e);
		}
	}
	sort(p,p+K+2,comp2);	//縦の辺を張る
	for (int i=0;i<K+1;i++){
		if (p[i].x==p[i+1].x){
			int cost=p[i+1].y-p[i].y;
			edge e{p[i+1].index+K+2,cost};
			G[p[i].index+K+2].push_back(e);
			e.to=p[i].index+K+2;
			G[p[i+1].index+K+2].push_back(e);
		}
	}
	for (int i=1;i<=K;i++){
		edge e{i+K+2,1};
		G[i].push_back(e);
		e.to=i;
		G[i+K+2].push_back(e);
	}
	long long res=dijkstra();
	if (res==INF){
		res=-1;
	}
	printf("%lld\n",res);
	return 0;
}