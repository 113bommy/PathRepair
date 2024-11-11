4
1 2#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  P a[n];
  int ans = 0;
  rep(i,n) cin >> a[i].first >> a[i].second;
  sort(a,a+n);
  vector<int> l(n), r(n);
  l[0] = a[0].second, r[n-1] = a[n-1].second;
  for(int i = 1; i < n; i++) {
    l[i] = min(l[i-1],a[i].second);
    r[n-i-1] = min(r[n-i],a[n-i-1].second);
  }
  rep(i,n) {
    int d = a[i].second - a[i].first + 1;
    if(i == 0) ans = max(ans,d+r[1]-a[n-1].first+1);
    else if(i == n-1) ans = max(ans,d+l[n-2]-a[n-2].first+1);
    else ans = max(ans,d+max(0,min(r[i+1],l[i-1])-a[n-1].first+1));
  }
  rep(i,n-1) ans = max(ans,max(l[i]-a[i].first+1,0)+max(r[i+1]-a[n-1].first+1,0));
  cout << ans << endl;
  return 0;
}