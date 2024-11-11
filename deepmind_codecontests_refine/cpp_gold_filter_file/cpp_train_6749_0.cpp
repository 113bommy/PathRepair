#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool f[110];
int main(){
  ll n;
  cin>>n;
  P a[110],b[110];
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  for(int i=0;i<n;i++)cin>>b[i].first>>b[i].second;
  sort(a,a+n);
  sort(b,b+n);
  ll ans=0;
  for(int i=0;i<n;i++){
    P num,yan;
    num=make_pair(-1,-1);
    yan=num;
    for(int j=0;j<n;j++){
      if(f[j])continue;
      if(a[j].first<b[i].first&&a[j].second<b[i].second){
        if(num.second<a[j].second){
          num.second=a[j].second;
          num.first=j;
        }
      }
    }
    if(num!=yan){
      ans++;
      f[num.first]=1;
    }
  }
  cout<<ans<<endl;
  return 0;
}