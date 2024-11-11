#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

struct Way{
	int p,q,cost;
	Way(){}
	Way(int _p,int _q,int _cost){
		p=_p; q=_q; cost=_cost;
	}
	bool operator<(const Way &a)const{
		return cost>a.cost;
	}
};

struct Node{
	int x,y;
};

int par[10000],_rank[10000];

void init(int n){
	for(int i=0;i<n;i++) par[i]=i,_rank[i]=1;
}

int find(int a){
	if(par[a]==a) return a;
	else return par[a] = find(par[a]);
}

void unite(int _a,int _b){
	int a = find(_a);
	int b = find(_b);
	if(a==b) return;
	if(_rank[a]>_rank[b]){
		par[b] = a;
	}
	else{
		par[a] = b;
		if(_rank[a]==_rank[b]) _rank[b]++;
	}
}

int main(){
	int N,M;
	Node node[10000];
	Way way[100000];
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>node[i].x>>node[i].y;
	}
	for(int i=0;i<M;i++){
		int a,b;
		cin>>way[i].p>>way[i].q;
		a = node[--way[i].p].x-node[--way[i].q].x;
		b = node[way[i].p].y-node[way[i].q].y;
		way[i].cost = a*a+b*b;
		//printf("\t%d\n",way[i].cost);
	}

	double ans=0;
	sort(way,way+M);
	init(N);
	for(int i=0;i<M;i++){
		int a = find(way[i].p),
			b = find(way[i].q);
		if(a!=b) unite(a,b);
		else ans += sqrt(way[i].cost);
	}
	printf("%lf\n",ans);
}