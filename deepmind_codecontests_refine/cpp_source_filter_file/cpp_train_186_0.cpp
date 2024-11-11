#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,k,q; cin >> n >> k >> q;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int ans = 1 << 30;
  for(int i = 0; i < n; i++){
    vector<int> v;
    for(int j = 0; j < n; j++){
      vector<int> t;
      while(j < n && a[j] <= a[i]){
        t.push_back(a[j]);
        j++;
      }
      sort(t.begin(),t.end());
      for(int l = 0; l < max(0LL,t.size()-k+1); l++){
        v.push_back(t[l]);
      }
    }
    if(v.size() < q) continue;
    sort(v.begin(),v.end());
    ans = min(ans,v[q-1] - v[0]);
  }
  cout << ans << endl;

  return 0;
}
