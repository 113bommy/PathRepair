#include<bits/stdc++.h>
using namespace std;
using Int = long long;


struct edge{
  Int from,to,cost,used;
  edge(){}
  edge(Int from,Int to,Int cost):from(from),to(to),cost(cost),used(0){}
  bool operator<(const edge& e) const{
    return cost<e.cost;
  }
};

struct Kruskal{

  struct UnionFind{
    Int n;
    vector<Int> r,p;
    UnionFind(){}
    UnionFind(Int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
    Int find(Int x){
      return (x==p[x]?x:p[x]=find(p[x]));
    }
    bool same(Int x,Int y){
      return find(x)==find(y);
    }
    void unite(Int x,Int y){
      x=find(x);y=find(y);
      if(x==y) return;
      if(r[x]<r[y]) swap(x,y);
      r[x]+=r[y];
      p[y]=x;
    }
  };
  

  Int n;
  vector<edge> edges;

  Kruskal(){}
  Kruskal(Int sz):n(sz){}
  
  void add_edge(Int u,Int v,Int c){
    edges.push_back(edge(u,v,c));
  }

  void input(Int m,Int offset=0){
    Int a,b,c;
    for(Int i=0;i<m;i++){
      cin>>a>>b>>c;
      add_edge(a+offset,b+offset,c);
    }
  }
  
  Int build(){
    sort(edges.begin(),edges.end());
    UnionFind uf(n+1);
    Int res=0;
    for(Int i=0;i<(Int)edges.size();i++){
      edge &e=edges[i];
      if(!uf.same(e.from,e.to)){
	res+=e.cost;
	uf.unite(e.from,e.to);
	e.used=1;
      }
    }
    return res;
  }
};


struct HLDecomposition {
  Int n,pos;
  vector<vector<Int> > G;
  vector<Int> vid, head, sub, hvy, par, dep, inv, type;
  
  HLDecomposition(){}
  HLDecomposition(Int sz):
    n(sz),pos(0),G(n),
    vid(n,-1),head(n),sub(n,1),hvy(n,-1),
    par(n),dep(n),inv(n),type(n){}
  
  void add_edge(Int u, Int v) {
    G[u].push_back(v);
    G[v].push_back(u);
  }

  void build(vector<Int> rs={0}) {
    Int c=0;
    for(Int r:rs){
      dfs(r);
      bfs(r, c++);
    }
  }
  
  void dfs(Int rt) {
    using T = pair<Int,int>;
    stack<T> st;
    par[rt]=-1;
    dep[rt]=0;
    st.emplace(rt,0);
    while(!st.empty()){
      Int v=st.top().first;
      Int &i=st.top().second;
      if(i<(Int)G[v].size()){
	Int u=G[v][i++];
	if(u==par[v]) continue;
	par[u]=v;
	dep[u]=dep[v]+1;
	st.emplace(u,0);
      }else{
	st.pop();
	Int res=0;
	for(Int u:G[v]){
	  if(u==par[v]) continue;
	  sub[v]+=sub[u];
	  if(res<sub[u]) res=sub[u],hvy[v]=u;
	}
      }
    }
  }

  void bfs(Int r,Int c) {
    Int &k=pos;
    queue<Int> q({r});
    while(!q.empty()){
      Int h=q.front();q.pop();
      for(Int i=h;i!=-1;i=hvy[i]) {
	type[i]=c;
	vid[i]=k++;
	inv[vid[i]]=i;
	head[i]=h;
	for(Int j:G[i])
	  if(j!=par[i]&&j!=hvy[i]) q.push(j);
      }
    }
  }
  
  // for_each(vertex)
  // [l,r] <- attention!!
  void for_each(Int u, Int v, const function<void(Int, Int)>& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      f(max(vid[head[v]],vid[u]),vid[v]);
      if(head[u]!=head[v]) v=par[head[v]];
      else break;
    }
  }
  
  // for_each(edge)
  // [l,r] <- attention!!
  void for_each_edge(Int u, Int v, const function<void(Int, Int)>& f) {
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]!=head[v]){
	f(vid[head[v]],vid[v]);
        v=par[head[v]];
      } else{
	if(u!=v) f(vid[u]+1,vid[v]);
	break;
      }
    }
  }

  Int lca(Int u,Int v){
    while(1){
      if(vid[u]>vid[v]) swap(u,v);
      if(head[u]==head[v]) return u;
      v=par[head[v]];
    }
  }

  Int distance(Int u,Int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};


template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  Int n;
  F f;
  G g;
  T d1;
  E d0;
  vector<T> dat;
  SegmentTree(){};
  SegmentTree(Int n_,F f,G g,T d1,
	      vector<T> v=vector<T>()):
    f(f),g(g),d1(d1){
    init(n_);
    if(n_==(Int)v.size()) build(n_,v);
  }
  void init(Int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
  }
  void build(Int n_, vector<T> v){
    for(Int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(Int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  void update(Int k,E a){
    k+=n-1;
    dat[k]=g(dat[k],a);
    while(k>0){
      k=(k-1)/2;
      dat[k]=f(dat[k*2+1],dat[k*2+2]);
    }
  }
  inline T query(Int a,Int b){
    T vl=d1,vr=d1;
    for(Int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[(l++)-1]);
      if(r&1) vr=f(dat[(--r)-1],vr);
    }
    return f(vl,vr);
  }
  
};


signed main(){
  Int n,m;
  cin>>n>>m;
  Kruskal k(n);
  k.input(m,-1);
  Int val=k.build();
  auto es=k.edges;
  es.erase(remove_if(es.begin(),es.end(),[](edge e){return !e.used;}),es.end());
  //cout<<es.size()<<endl;
  //for(auto e:es) cout<<e.used<<endl;
  HLDecomposition hld(n);
  for(auto e:es) hld.add_edge(e.from, e.to);
  hld.build();
  
  SegmentTree<Int, Int> seg(n,
			    [](Int a,Int b){return max(a,b);},
			    [](Int a,Int b){return b;},
			    0);
  for(auto e:es){
    Int u=e.from,v=e.to,c=e.cost;
    if(hld.dep[u]>hld.dep[v]) swap(u,v);
    seg.update(hld.vid[v],c);
  }
  
  Int q;
  cin>>q;
  //if(q>3000) exit(1);
  for(Int i=0;i<q;i++){
    Int s,t;
    cin>>s>>t;
    s--;t--;
    Int x=0;
    hld.for_each_edge(s,t,[&](Int l,Int r){
	x=max(x,seg.query(l,r+1));
      });
    cout<<val-x<<endl;
  }
  return 0;
}
