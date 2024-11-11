#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; cin >> ar[i++])
      ;
    long long maxx = 1;
    while (maxx < 1e16) maxx *= k;
    while (maxx) {
      sort(ar, ar + n);
      reverse(ar, ar + n);
      if (ar[0] >= maxx) ar[0] -= maxx;
      maxx /= k;
    }
    sort(ar, ar + n);
    reverse(ar, ar + n);
    bool flag = 1;
    for (int i = 0; i < n; i++)
      if (ar[i] != 0) flag = 0;
    cout << (flag ? "YES\n" : "NO\n");
  }
  return 0;
}
