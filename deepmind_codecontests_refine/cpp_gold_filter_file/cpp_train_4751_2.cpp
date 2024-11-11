#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, mod = 1e9 + 7;
int a[N];
signed main() {
  int n, m, k, t, ans = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> t;
    t--;
    a[t] = 1;
  }
  int c = 0;
  for (int i = 0; i < N; i++) {
    c += a[i];
    if (i >= m) c -= a[i - m];
    if (c == k) {
      ans++;
      a[i] = 0;
      c--;
    }
  }
  cout << ans;
}
