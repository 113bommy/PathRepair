#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int n, x[5005], y[5005], g[5005][5005];
int c[12500005], cnt, mx;
bool mk[5005], col[5005];
long long Pow(int a) {
  if (a == 0) return 1;
  long long tmp = Pow(a >> 1);
  if (a & 1) return tmp * tmp % mod * 2 % mod;
  return tmp * tmp % mod;
}
bool dfs(int u, bool val) {
  mk[u] = 1;
  col[u] = val;
  for (int i = 1; i <= n; i++) {
    if (i == u) continue;
    if (g[u][i] <= mx) continue;
    if (mk[i] && col[i] == val) return false;
    if (!mk[i] && !dfs(i, val ^ 1)) return false;
  }
  return true;
}
bool check(int limit) {
  mx = c[limit];
  memset(mk, 0, sizeof(mk));
  memset(col, 0, sizeof(col));
  for (int i = 1; i <= n; i++)
    if (!mk[i] && !dfs(i, 0)) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    for (int j = 1; j < i; j++) {
      g[j][i] = g[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
      c[++cnt] = g[i][j];
    }
  }
  sort(c, c + cnt + 1);
  int l = 0, r = cnt, mid, ans = cnt;
  while (l <= r) {
    mid = l + r >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d\n", c[ans]);
  mx = c[ans];
  ans = 0;
  memset(mk, 0, sizeof(mk));
  memset(col, 0, sizeof(col));
  for (int i = 1; i <= n; i++) {
    if (!mk[i]) {
      dfs(i, 0);
      ans++;
    }
  }
  printf("%lld", Pow(ans));
  return 0;
}
