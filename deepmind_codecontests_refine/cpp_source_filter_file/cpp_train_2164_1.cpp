#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct E{ll to,co,ti;};
struct P{ll ti,id,re;};
bool operator <(const P &a,const P &b){return a.tim>b.tim;}
ll d[50][5001],c[50],d[50],ans[50],n,m,s;
vector<E> edge[50];
priority_queue<P> que;

signed main(){
  cin>>n>>m>>s;
  while(m--){
    ll u,v,a,b;cin>>u>>v>>a>>b;u--;v--;
    edge[u].push_back({v,a,b});
    edge[v].push_back({u,a,b});
  }
  for(ll i=0;i<n;i++)cin>>c[i]>>d[i];
  que.push({1,0,min(5000LL,s)});
  while(que.size()){
    P p=que.top();que.pop();
    if(d[p.id][p.re])continue;
    d[p.id][p.re]=p.ti;
    if(!ans[p.id])ans[p.id]=p.ti;
    for(E q:edge[p.id])
      if(p.re>=q.co&&!d[q.to][p.re-q.co])
        que.push({p.ti+q.ti,q.to,p.re-q.co});
    if(p.re+c[p.id]<=5000)que.push({p.ti+d[p.id],p.id,p.re+c[p.id]});
  }
  for(ll i=1;i<n;i++)cout<<--ans[i]<<endl;
}
