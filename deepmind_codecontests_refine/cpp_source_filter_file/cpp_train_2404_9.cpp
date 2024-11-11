#include <bits/stdc++.h>
using namespace std;
map<long long, long long> cnt[21][21];
long long n, m, k, ans;
long long a[21][21], v[21][21];
void dfs(long long x, long long y, long long now) {
  if (x > n or y > m) return;
  if (v[x][y]) return cnt[x][y][now ^ a[x][y]]++, void();
  dfs(x + 1, y, now ^ a[x][y]);
  dfs(x, y + 1, now ^ a[x][y]);
}
void dfs1(long long x, long long y, long long now) {
  if (x < 1 or y < 1) return;
  if (v[x][y]) return ans += cnt[x][y][now ^ k], void();
  dfs1(x - 1, y, now ^ a[x][y]);
  dfs1(x, y - 1, now ^ a[x][y]);
}
signed main() {
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  for (long long i = 1; i <= n and i <= m; i++) v[i][n - i + 1] = 1;
  dfs(1, 1, 0);
  dfs1(n, m, 0);
  cout << ans;
}
