#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int mod = 1000000007;
int lowbit(int x) { return x & (-x); }
int fast_power(int a, int b) {
  int x;
  for (x = 1; b; b >>= 1) {
    if (b & 1) x = 1ll * x * a % mod;
    a = 1ll * a * a % mod;
  }
  return x % mod;
}
int n, m;
int ans[100005];
bool check(int n, int m) {
  if (n % 2 == 0) return 0;
  if (m < 0 && m > max(0, (n - 3) / 2)) return 0;
  if (!m) return !(n & (n + 1));
  if (m == 1) return (n & (n + 1));
  if (n == 9 && m == 2) return 0;
  return 1;
}
void dfs(int u, int t, int s, int fa) {
  ans[u] = fa;
  if (t == 1) return;
  for (int lsz = 1; lsz < t; lsz = lsz * 2 + 1) {
    int rsz = t - lsz - 1;
    int rs = s - (max(lsz, rsz) >= 2 * min(lsz, rsz));
    if (check(lsz, 0) && check(rsz, rs)) {
      dfs(u + 1, lsz, 0, u);
      dfs(u + lsz + 1, rsz, rs, u);
      return;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  if (check(n, m)) {
    puts("YES");
    dfs(1, n, m, 0);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  } else
    puts("NO");
  return 0;
}
