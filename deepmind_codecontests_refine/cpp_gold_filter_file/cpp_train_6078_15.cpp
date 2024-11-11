#include <bits/stdc++.h>
using namespace std;
const int MD = 1000000007;
inline void add(int &a, const int b) {
  a += b;
  if (a >= MD) a %= MD;
}
inline int mul(const int &a, const int &b) {
  long long r = 1ll * a * b;
  if (r >= MD) r %= MD;
  return r;
}
int a[9], n, k;
bool vis[9];
bool ok(int x) {
  if (x == 1) return 1;
  vis[x] = 1;
  if (!vis[a[x]] && ok(a[x])) return 1;
  return 0;
}
bool check() {
  for (int i = 1; i <= k; ++i) {
    memset(vis, 0, sizeof vis);
    if (!ok(a[i])) return 0;
  }
  return 1;
}
int dfs(int x) {
  if (x == k + 1) {
    if (check()) return 1;
    return 0;
  }
  int ret = 0;
  for (int i = 1; i <= k; ++i) a[x] = i, ret += dfs(x + 1);
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  int ans = 1;
  for (int i = k + 1; i <= n; ++i) ans = mul(ans, n - k);
  printf("%d\n", mul(ans, dfs(1)));
  return 0;
}
