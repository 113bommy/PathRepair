#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
const int maxn = 100003;
int n, m, f[maxn], sz, a[maxn], Q, pw[maxn], inv[maxn];
vector<pair<int, int> > v[maxn];
map<int, int> g;
int qpow(int x, int p) {
  int rt = 1;
  while (p) {
    if (p & 1) rt = (1ll * rt * x) % mo;
    x = (1ll * x * x) % mo;
    p >>= 1;
  }
  return rt;
}
char s[maxn];
int ans[maxn], fac[maxn], invf[maxn];
int C(int x, int y) { return 1ll * fac[x] * invf[y] % mo * invf[x - y] % mo; }
int main() {
  int T_T;
  fac[0] = invf[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    fac[i] = 1ll * fac[i - 1] * i % mo;
    invf[i] = qpow(fac[i], mo - 2);
  }
  scanf("%d", &T_T);
  scanf("%s", s);
  int cur = strlen(s);
  while (T_T--) {
    int o;
    scanf("%d", &o);
    if (o == 1) {
      scanf("%s", s);
      cur = strlen(s);
    } else {
      int d;
      scanf("%d", &d);
      if (g.find(cur) == g.end()) a[g[cur] = ++sz] = cur;
      v[g[cur]].push_back(make_pair(d, ++Q));
    }
  }
  inv[0] = pw[0] = 1;
  int p = qpow(26, mo - 2);
  for (int i = 1; i < maxn; ++i) {
    pw[i] = 1ll * pw[i - 1] * 25 % mo;
    inv[i] = 1ll * inv[i - 1] * p % mo;
  }
  for (int i = 1; i <= sz; ++i) {
    sort(v[i].begin(), v[i].end());
    int n;
    memset(f, 0, sizeof(f));
    for (int j = a[i]; j < maxn; ++j) {
      f[j] = (f[j - 1] +
              1ll * C(j - 1, a[i] - 1) * pw[j - a[i]] % mo * inv[j] % mo) %
             mo;
    }
    for (int j = 0; j < v[i].size(); ++j) {
      n = v[i][j].first;
      ans[v[i][j].second] = 1ll * f[n] * qpow(26, n) % mo;
    }
  }
  for (int i = 1; i <= Q; ++i) printf("%d\n", ans[i]);
  return 0;
}
