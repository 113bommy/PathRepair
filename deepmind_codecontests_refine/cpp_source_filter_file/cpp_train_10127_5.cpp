#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 7;
long long a[M];
long long dp[M][3], n;
long long call(int pos, int op) {
  if (pos == n) return 0;
  if (dp[pos][op] != -1) return dp[pos][op];
  long long p = 0, q = 0;
  p = call(pos + 1, op);
  if (op & 1) {
    q = -a[pos] + call(pos + 1, op ^ 1);
  } else
    q = a[pos] + call(pos + 1, op ^ 1);
  return dp[pos][op] = max(p, q);
}
void solve() {
  int q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) dp[i][j] = -1;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  int res = call(0, 0);
  cout << res << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
