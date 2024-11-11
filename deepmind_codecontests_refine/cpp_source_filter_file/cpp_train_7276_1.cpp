#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
typedef long long ll;
typedef pair<ll,ll> P;
struct edge{
  ll to,cost;
  edge(ll t,ll c){
    to=t,cost=c;
  }
};
struct state{
  ll pos,flg,cost;
  state(ll p,ll f,ll c){
    pos=p,flg=f,cost=c;
  }
  bool operator < (const state &p)const{
    return cost > p.cost;
  }
};
 
vector<P> t[MAX][2];
ll W,H,K,X[MAX],Y[MAX];
ll d[MAX][2];
vector<edge> G[MAX][2];
 
ll solve(){
  if(t[1][0].empty())return -1;
  for(int i=0;i<MAX;i++)d[i][0]=d[i][1]=10000000000000000LL;
  priority_queue< state > Q;
  P p=t[1][0][0];
  Q.push( state( p.second, 0, p.first-1 ) );
  d[p.second][0]=p.first-1;
   
  while(!Q.empty()){
    state s=Q.top();Q.pop();
    if(s.cost>d[s.pos][s.flg])continue;
    for(int f=0;f<2;f++){
      int nf=(s.flg+f)%2;
      for(int i=0;i<(int)G[s.pos][nf].size();i++){
        edge e=G[s.pos][nf][i];
        ll ncost=s.cost+e.cost+f;
        if(e.cost==0)ncost=s.cost;
        if(ncost<d[e.to][nf]){
          d[e.to][nf]=ncost;
          Q.push( state(e.to,nf,ncost) );
        }
      }
    }
  }
  ll res=min(d[K][0],d[K][1]);
  if(res==10000000000000000LL;)return -1;
  else return res;
}
       
int main(){
  scanf("%lld %lld %lld",&W,&H,&K);
  for(int i=0;i<K;i++){
    scanf("%lld %lld",&X[i],&Y[i]);
    t[X[i]][0].push_back(P(Y[i],i));
    t[Y[i]][1].push_back(P(X[i],i));
  }
  t[W][0].push_back(P(H,K));
  t[H][1].push_back(P(W,K));
  X[K]=W;
  Y[K]=H;
  for(int i=1;i<=100000;i++){
    for(int f=0;f<2;f++){
      vector<P> &vec=t[i][f];
      sort(vec.begin(),vec.end());
      int size=vec.size();
      for(int j=0;j<size;j++){
        P p=vec[j],q;
        if(0<j){
          q=vec[j-1];
          G[p.second][f].push_back( edge(q.second,p.first-q.first) );
        }
        if(j+1<size){
          q=vec[j+1];
          G[p.second][f].push_back( edge(q.second,q.first-p.first) );
        }
      }
    }
  }
  cout<<solve()<<endl; 
  return 0;
}