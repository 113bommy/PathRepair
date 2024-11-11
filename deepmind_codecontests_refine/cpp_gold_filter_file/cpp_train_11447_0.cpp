#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
using namespace std;

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) (sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg)),arg)
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)

template<class T>void reg(vector<T> &ary,const T &elem){ary.emplace_back(elem);}
template<class T>bool chmin(T &a, const T &b) {return (b<a)?(a=b,1):0;}
template<class T>bool chmax(T &a, const T &b) {return (a<b)?(a=b,1):0;}

using R=long double; // __float128
const R EPS = 1E-8; // [-100:100]->EPS=1e-9 [-1000:1000]->EPS=1e-8 [-10000:10000]->EPS=1e-7
const R INF = 1E40;
const R PI = acos(R(-1));
inline int sgn(const R& r){ return (r > EPS) - (r < -EPS);}
inline R sq(R x){return sqrt(max<R>(x,0.0));}

using P=complex<R>;
using VP=vector<P>;
const P O=P(0,0);

namespace std{
	bool operator <  (const P& a,const P& b){ return sgn(real(a-b))?real(a-b)<0:sgn(imag(a-b))<0;}
	bool operator == (const P& a,const P& b){ return sgn(real(a-b))==0 && sgn(imag(a-b))==0;}
}

using L=struct{P s,t;};

inline R dot(P o,P a,P b){a-=o,b-=o; return real(conj(a)*b);}
inline R det(P o,P a,P b){a-=o,b-=o; return imag(conj(a)*b);}

enum CCW{ LEFT = 1,RIGHT = 2,BACK = 4,FRONT = 8,ON = 16};
inline int ccw(P o,P a, P b) {
	if (sgn(det(o,a,b)) > 0) return LEFT;
	if (sgn(det(o,a,b)) < 0) return RIGHT;
	if (sgn(dot(o,a,b)) < 0) return BACK;
	if (sgn(norm(a-o)-norm(b-o)) < 0) return FRONT;
	return ON;
}

// above prepared template

bool iss(L a,L b,int end=0){
	int s1=ccw(a.s,a.t,b.s)|ccw(a.s,a.t,b.t);
	int s2=ccw(b.s,b.t,a.s)|ccw(b.s,b.t,a.t);
	if(end) return (s1&s2)==(LEFT|RIGHT);
	return (s1|s2)&ON || (s1&s2)==(LEFT|RIGHT);
}


R dsp(L s,P p){
	if(sgn(dot(s.s,s.t,p))<=0) return abs(p-s.s);
	if(sgn(dot(s.t,s.s,p))<=0) return abs(p-s.t);
	return abs(det(s.s,s.t,p))/abs(s.t-s.s);
}

R dss(L a,L b){return iss(a,b)?0:min({dsp(a,b.s),dsp(a,b.t),dsp(b,a.s),dsp(b,a.t)});}


using edge=struct {int to;R cost;};
using G=vector<vector<edge>>;
const R inf=1e60;

vector<R> dijkstra(const G &graph,int s){
	const int n=graph.size();
	vector<R> dist(n,inf);
	using state=tuple<R,int>;
	priority_queue<state,vector<state>,greater<state>> q;
	dist[s]=0.0,q.push(state(0.0,s));
	
	while(!q.empty()){
		R c; int v;
		tie(c,v)=q.top();q.pop();
		for(auto &e:graph[v]){
			R nc=c+e.cost; int nv=e.to;
			if(chmin(dist[nv],nc)) q.push(state(nc,nv));
		}
	}

	return dist;
}

int main(void){
	int w,m;
	cout.precision(20);
	while(cin >> w >> m,w){
		vector<L> pol[210];

		rep(i,m){
			int n,x[55],y[55];
			cin >> n;
			rep(j,n) cin >> x[j] >> y[j];
			rep(j,n) pol[i].push_back({P(x[j],y[j]),P(x[(j+1)%n],y[(j+1)%n])});
		}

		const int s=m,t=m+1,n=m+2;
		const L sl={P(0,-1e5),P(0,1e5)},tl={P(w,-1e5),P(w,1e5)};
		G graph(n);

		rep(i,m){
			R d=inf;
			for(auto &l:pol[i]) chmin(d,dss(l,sl));
			graph[s].push_back({i,d});
			graph[i].push_back({s,d});
		}

		rep(i,m){
			R d=inf;
			for(auto &l:pol[i]) chmin(d,dss(l,tl));
			graph[t].push_back({i,d});
			graph[i].push_back({t,d});
		}

		rep(j,m)rep(i,j){
			R d=inf;
			for(auto &il:pol[i])
				for(auto &jl:pol[j]) 
					chmin(d,dss(il,jl));
			graph[i].push_back({j,d});
			graph[j].push_back({i,d});
		}

		graph[s].push_back({t,R(w)});
		graph[t].push_back({s,R(w)});
		
		auto dist=dijkstra(graph,s);
		cout << fixed << dist[t] << endl;
 	}
	return 0;
}