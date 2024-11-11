#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int Par[100],Rank[100];
void Init(int n) {
	for(int i=0;i<n;i++) {
		Par[i]=i;
		Rank[i]=0;
	}
}
int Find(int x) {
	if(Par[x]==x) {
		return x;
	}else {
		return Par[x]=Find(Par[x]);
	}
}
void Unite(int x,int y) {
	x=Find(x);
	y=Find(y);
	if(x==y) return;
	if(Rank[x]<Rank[y]) {
		Par[x]=y;
	}else {
		Par[y]=x;
		if(Rank[x]==Rank[y])Rank[x]++;
	}
}
bool Same(int x,int y) {
	return Find(x)==Find(y);
}
struct Edge {
	int from,to,cost;
	Edge(int _f,int _t,int _c) {from=_f,to=_t,cost=_c;}
	bool operator < (const Edge& E) {return cost<E.cost;}
};
int main() {
	int n,m;
	while(scanf("%d %d",&n,&m),n) {
		vector<Edge> es;
		for(int i=0;i<m;i++) {
			int a,b,cost;
			scanf("%d %d %d",&a,&b,&cost);
			es.push_back(Edge(a,b,cost));
		}
		sort(es.begin(),es.end());
		Init(n);
		int sum=0;
		for(int i=0;i<es.size();i++) {
			if(!Same(es[i].from,es[i].to)) {
				Unite(es[i].from,es[i].to);
				sum+=es[i].cost;
			}
		}
		printf("%d\n",sum);
	}
}