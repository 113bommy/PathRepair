#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k, d, ans = 200;
    cin >> n >> k >> d;
    int arr[n], i, j;
    set<int> s;
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 0; i < n; i++) {
      for (j = i; j < (d + i); j++) {
        s.insert(arr[j]);
      }
      if (ans > s.size()) ans = s.size();
      s.clear();
    }
    cout << ans << endl;
  }
}
