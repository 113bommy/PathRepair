#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
#define pu push
#define pb push_back
#define mp make_pair
#define INF 10000000000000000
int n,m;
ll start[100005];
ll goal[100005];
ll d[100005];
pair<ll,ll> qwe[100005];
struct edge{
	int to; ll cost;
	edge(int a,int b):to(a),cost(b){}
};
vector<edge>vec[100005];
void dijkstra1(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	que.pu(mp(0,s));
	fill(d,d+n,INF);
	d[s]=0;
	while(!que.empty()){
		P p=que.top(); que.pop();
		int V=p.second;
		if(d[V]<p.first) continue;
		for(int i=0;i<vec[V].size();i++){
			edge e=vec[V][i];
			if(d[e.to] > d[V]+e.cost){
				d[e.to]=d[V]+e.cost;
				que.push(mp(d[e.to],e.to));
			}
		}
	}
}
vector<ll>seg[1<<18];
ll limits,limite;
void update1(vector<ll> x,int a){
	seg[a+(1<<17)-1]=x;
}
void update(){
		for(int i=(1<<17)-2;i>=0;i--){
		seg[i].resize(seg[i*2+1].size()+seg[i*2+2].size());
		merge(seg[i*2+1].begin(),seg[i*2+1].end(),seg[i*2+2].begin(),seg[i*2+2].end(),seg[i].begin());
		}
}
int sum(int a,int b,int k,int l,int r){
	if(l>b || a>r){
		return 0;
	}else if(a<=l && r<=b){
		int rp=lower_bound(seg[k].begin(),seg[k].end(),limite)-seg[k].begin();
		return seg[k].size()-rp; 
	}else{
		return sum(a,b,k*2+1,l,(l+r)/2)+sum(a,b,k*2+2,(l+r)/2+1,r);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		scanf("%d %d %lld",&a,&b,&c);
		vec[a].pb(edge(b,c)); vec[b].pb(edge(a,c));
	}
	dijkstra(0);
	for(int i=0;i<n;i++){
		start[i]=d[i];
	}
	dijkstra(n-1);
	for(int i=0;i<n;i++){
		goal[i]=d[i];
		qwe[i]=mp(start[i],goal[i]);
	}
	sort(qwe,qwe+n);
	for(int i=0;i<n;i++){
		vector<ll>er; er.pb(qwe[i].second);
		update1(er,i); start[i]=qwe[i].first;
	}
	update();
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		scanf("%lld %lld",&limits,&limite);
		int eo=upper_bound(start,start+n,limits)-start;
		printf("%d\n",sum(0,eo-1,0,0,(1<<17)-1));
	}
}