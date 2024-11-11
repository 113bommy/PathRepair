#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
const long long LINF=1e18;
template<typename T>
void chmin(T &a,T b){
  if(a>b)a=b;
}
template<typename T>
void chmax(T &a,T b){
  if(a<b)a=b;
}

signed main(){
  int x,k;cin>>x>>k;
  vector<int> r(k); for(int &p:r)cin>>p;
  r.push_back(LINF);
  int q;cin>>q;
  vector<P> qu(q); for(P &p:qu){int t,a;cin>>t>>a;p=P(t,a);}
  int now=0,de=0,fl=1,low=0,high=x;
  int A=x;
  for(P _:qu){
    int t=_.first,a=_.second;
    while(now<=k&&r[now]<=t){
      de+=fl*(r[now]-(now>0?r[now-1]:0));
      chmin(high,x+de);
      chmax(low,de);
      A-=fl*(r[now]-(now>0?r[now-1]:0));chmax(A,0LL);chmin(A,x);
      fl*=-1;now++;
    }
    int ans,w=-de-fl*(t-(now?r[now-1]:0));
    if(a<low)ans=low+w;
    else if(a>high)ans=high+w;
    else ans=a+w;
    if(high<low)ans=A-fl*(t-(now?r[now-1]:0));
    chmax(ans,0);
    chmin(ans,x);
    cout<<ans<<endl;
  }
}
