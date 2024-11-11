#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 2005;
int n;
int fa[N], v[N], st, ed;
char s[N];
int ans = 0;
long long qp(int x, int l) {
  int ret = 1;
  while (l) {
    if (l & 1) ret = 1ll * ret * x % mod;
    l >>= 1;
    x = 1ll * x * x % mod;
  }
  return ret;
}
int finds(int x) {
  if (fa[x] == x) return x;
  int now = finds(fa[x]);
  v[x] ^= v[fa[x]];
  fa[x] = now;
  return fa[x];
}
int merge(int x, int y, int z) {
  int fx = finds(x), fy = finds(y);
  if (fx == fy) return v[fx] ^ v[fy] ^ z ^ 1;
  fa[fx] = fy;
  v[fx] = v[x] ^ v[y] ^ z;
  return 1;
}
int calc(int len) {
  for (int i = 1; i <= ed; ++i) fa[i] = i, v[i] = 0;
  for (int i = 1; i <= n / 2; ++i) merge(i, n - i + 1, 0);
  for (int i = 1; i <= len / 2; ++i) merge(n + i, n + len - i + 1, 0);
  for (int i = len + 1; i <= n; ++i) merge(n + i, ed, 0);
  merge(1, st, 0);
  merge(n + 1, st, 0);
  for (int i = 1; i <= n; ++i) {
    if (s[n - i + 1] != '?') {
      if (!merge(n + i, i, s[n - i + 1] - '0')) return 0;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= ed; ++i) cnt += (fa[i] == i);
  return qp(2, cnt - 1);
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  st = 2 * n + 1;
  ed = st + 1;
  for (int i = 1; i < n; ++i) ans = (ans + calc(i)) % mod;
  printf("%d\n", ans);
  return 0;
}
