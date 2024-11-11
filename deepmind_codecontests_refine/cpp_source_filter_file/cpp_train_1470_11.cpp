#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
const int maxm = 2000005;
const int mxm = 2000000;
const int mod = (1e9) + 7;
int n, m, i, j, t, k, s, p[maxn], pri[maxm], tot, fa[maxm], buc[maxm];
bool vis[maxm], ff[maxn], ocp[maxn];
bool cmp(int x, int y) { return x > y; }
inline int Pow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1ll * ret * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return ret;
}
int main() {
  for (i = 2; i <= mxm; ++i) {
    if (!vis[i]) {
      pri[++tot] = i;
      fa[i] = tot;
    }
    for (j = 1; j <= tot; ++j) {
      if (i * pri[j] > mxm) break;
      vis[i * pri[j]] = 1;
      fa[i * pri[j]] = j;
      if (i % pri[j] == 0) break;
    }
  }
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
  }
  sort(p + 1, p + n + 1, cmp);
  s = 1;
  for (i = 1; i <= n; ++i) {
    if (!buc[fa[p[i]]]) {
      ff[i] = 1;
      buc[fa[p[i]]]++;
      s = 1ll * s * p[i] % mod;
      continue;
    }
    t = p[i] - 1;
    while (t > 1) {
      int now = fa[t], ct = 0;
      while (t % pri[now] == 0) t /= pri[now], ++ct;
      if (ct > buc[now]) {
        s = 1ll * s * Pow(pri[now], ct - buc[now]) % mod;
        buc[now] = ct;
      }
    }
  }
  for (i = 1; i <= n; ++i) {
    if (ff[i]) continue;
    t = p[i] - 1;
    bool flg = 1;
    while (t > 1) {
      int now = fa[t], ct = 0;
      while (t % pri[now] == 0) t /= pri[now], ++ct;
      if (ct == buc[now] && !ocp[now]) ocp[now] = 1, flg = 0;
    }
    if (flg) {
      s = (s + 1) % mod;
      break;
    }
  }
  printf("%d\n", s);
  return 0;
}
