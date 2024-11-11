#include <bits/stdc++.h>
using namespace std;
const int N = 100200, K = 110, MOD = (int)(1e9 + 7);
int ans[N], n, m, jc[N], inv[N];
int power(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}
int comb(int a, int b) {
  if (a < 0 || b < 0 || a < b) return 0;
  return 1ll * jc[a] * inv[b] % MOD * inv[a - b] % MOD;
}
vector<pair<int, int> > mod[K];
struct data {
  int l, r, k;
};
vector<data> dat[2];
void doit(int p, int dep) {
  if ((!dat[p].size()) && (!mod[dep].size())) return;
  dat[p ^ 1].clear();
  int x, y, z;
  for (int i = 0; i < (int)dat[p].size(); ++i) {
    x = dat[p][i].l, y = dat[p][i].r, z = dat[p][i].k;
    if (z == 0) {
      mod[dep + 1].push_back(pair<int, int>(x, 1));
      mod[dep + 1].push_back(pair<int, int>(y + 1, -1));
    } else {
      dat[p ^ 1].push_back((data){x, y, z - 1});
      mod[dep + 1].push_back(pair<int, int>(y + 1, -comb(y - x + z, z)));
    }
  }
  doit(p ^ 1, dep + 1);
  for (int i = 1; i <= n; ++i) (ans[i] += ans[i - 1]) %= MOD;
  for (int i = 0; i < (int)mod[dep].size(); ++i)
    (ans[mod[dep][i].first] += mod[dep][i].second) %= MOD;
}
void prework() {
  jc[0] = 1;
  for (int i = 1; i <= n + 100; ++i) jc[i] = 1ll * jc[i - 1] * i % MOD;
  inv[n + 100] = power(jc[n + 100], MOD - 2);
  for (int i = n + 99; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % MOD;
}
int rec[N];
int main() {
  int x, y, z;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &rec[i]);
  prework();
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d%d", &x, &y, &z);
    dat[0].push_back((data){x, y, z});
  }
  doit(0, 1);
  for (int i = 1; i <= n; ++i) ans[i] = ((ans[i] + rec[i]) % MOD + MOD) % MOD;
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  puts("");
  return 0;
}
