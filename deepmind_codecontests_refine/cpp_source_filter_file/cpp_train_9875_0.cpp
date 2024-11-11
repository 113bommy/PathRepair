#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  pair<ll,ll> p[n];
  rep(i,n){
    cin >> a[i];
    p[i]=mp(a[i],i);
  }
  sort(p,p+n);
  reverse(p,p+n);

  ll ans[n];
  rep(i,n) ans[i]=0;
  int ind=n;
  rep(i,n){
    ind=min(ind, p[i].second);
    if(i==n-1) ans[ind]+=(i+1)*(p[i].first-0);
    else ans[ind]+=(i+1)*(p[i].first-p[i+1].first);
    //    cout << ans[ind] << endl;
  }
  rep(i,n){
    cout << ans[i] << endl;
  }
  
  return 0;
    

}
