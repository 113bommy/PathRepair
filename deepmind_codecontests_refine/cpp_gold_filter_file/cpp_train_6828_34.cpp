#include <bits/stdc++.h>
using namespace std;
int t = 1;
const int M = 355, N = 100005;
int ans[M][N];
void solve() {
  memset(ans, 0, sizeof ans);
  int n;
  cin >> n;
  vector<int> v(n + 5);
  for (int i = 1; i < n + 1; i += 1) cin >> v[i];
  for (int i = 1; i < M; i += 1) {
    for (int j = n; j >= 1; j--) {
      if (j + v[j] + i > n)
        ans[i][j] = 1;
      else {
        ans[i][j] = 1 + ans[i][j + v[j] + i];
      }
    }
  }
  int q, p, k;
  cin >> q;
  while (q--) {
    cin >> p >> k;
    if (k < M) {
      cout << ans[k][p] << "\n";
    } else {
      int val = 1;
      while (p + v[p] + k <= n) {
        p = p + v[p] + k;
        val++;
      }
      cout << val << "\n";
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (t--) {
    solve();
  }
  return 0;
}
