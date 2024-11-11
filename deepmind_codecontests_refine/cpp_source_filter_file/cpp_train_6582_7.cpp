#include <bits/stdc++.h>
using namespace std;
long long int n, m, t, dp[31][31];
long long int first(long long int n, long long int r) {
  if (n <= r || r == 0 || n == 0) return 1;
  long long int& ans = dp[n][r];
  if (ans != -1) return ans;
  return ans = first(n - 1, r) + first(n - 1, r - 1);
}
void solve() {
  long long int ans = 0;
  for (int i = 4; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (i + j <= t) ans += first(n, 4) * first(m, 1);
  cout << ans << '\n';
  return;
}
int main() {
  clock_t beg = clock();
  {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
  };
  cin >> n >> m >> t;
  for (int i = 0; i < 31; i++)
    for (int j = 0; j < 31; j++) dp[i][j] = -1;
  solve();
  clock_t end = clock();
  fprintf(stderr, "%.3f sec\n", (double)(end - beg) / CLOCKS_PER_SEC);
  return 0;
}
