#include <bits/stdc++.h>
#define ll long long
#define INF 999999999
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef pair<int,int>P;
typedef pair<ll,ll>pl;

const int MAX_N = 40;

ll n,lm;
ll v[MAX_N];
ll w[MAX_N];
vector<pl> x,y;

void func(int si,int ti,vector<P> &x){
  int size=ti-si;
  rep(bit,1<<size){
    pl p=pl(0,0);
    for(int i=0;i<size;i++){
      if(bit>>i&1){
        p.first+=w[si+i];
        p.second+=v[si+i];
      }
    }
    x.push_back(p);
  }
}
  
int main(){
  cin>>N>>W;
  for(int i=0;i<N;i++)cin>>v[i]>>w[i];
    
  func(0,N/2,x);
  sort(x.begin(),x.end());
  func(N/2,N,y);
  sort(y.begin(),y.end());
    
  ll target=0,maxm=-(1LL<<60),ans=0;
    
  for(int i=(int)x.size()-1;i>=0;i--){
    pl p=x[i];
    while(target<(int)y.size() && p.first+y[target].first <=W ){
      maxm=max(maxm,y[target].second);
      target++;
    }
    ans=max(ans,maxm+p.second);
  }
  
  cout<<ans<<endl;
  return 0;
}