#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
int main(){
  int n,q;cin>>n>>q;
  vector<PP> p(n);
  rep(i,n){
    int s,t,x;scanf("%d %d %d",&s,&t,&x);
    get<2>(p[i])=x-t+1;
    get<1>(p[i])=x-s;
    get<0>(p[i])=x;
  }
  sort(p.begin(),p.end());
  set<P> s;
  vi ans(q,-1);
  rep(i,q){
    int a;scanf("%d",&a);
    s.insert(P(-a,i));
  }
  rep(i,n){
    if(s.size()==0)break;
    int a=get<2>(p[i]),b=get<1>(p[i]);
    auto from=s.lower_bound(P(a,-1));
    while(from!=s.end()){
      if((from->first)>get<1>(p[i]))break;
      ans[from->second]=get<0>(p[i]);
      s.erase(from++);
    }
  }
  rep(i,q)printf("%d\n",ans[i]);
}
