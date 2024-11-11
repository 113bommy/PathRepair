#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[100005],b[100005];
int main(){
  ll n;
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<n;i++) cin>>b[i];
  vector<P> pv;
  for(int i=0;i<n;i++) pv.push_back(P(b[i],a[i]));
  sort(pv.begin(),pv.end());
  for(int i=0;i<n;i++){
    a[i]=pv[i].second;
    b[i]=pv[i].first;
  }
  vector<P> av;
  for(int i=0;i<n;i++) av.push_back(P(a[i],i+1));
  sort(av.begin(),av.end());
  for(int i=0;i<n;i++){
    if(av[i].first>pv[i].first){
      cout<<"No"<<endl;
      return 0;
    }
  }
  vector<bool> used(100005,false);
  ll pos=1;
  while(!used[pos]){
    used[pos]=true;
    pos=av[pos-1].second;
  }
  bool f=true;
  for(int i=1;i<=n;i++){
    if(!used[i]) f=false;
  }
  if(!f){
    cout<<"Yes"<<endl;
    return 0;
  }
  for(int i=0;i<n-1;i++){
    if(av[i+1].first<=pv[i].first){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}
