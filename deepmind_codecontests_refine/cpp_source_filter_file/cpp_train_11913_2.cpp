#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100010];
int ind[100010];
vector<int> f[100010], inv[100010];
int lcnt[100010];
int ccnt[100010];
int cc = 0, cl[100010];
int sl[1 << 13], bitcnt[1 << 13];
bool vis[100010];
void dfs(int p, int c) {
  vis[p] = true;
  ++c;
  if (a[p] == 0)
    ++lcnt[c], ++cc, cl[cc] = c;
  else if (vis[a[p]])
    ++ccnt[c];
  else
    dfs(a[p], c);
  return;
}
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % 1000000007;
    a = 1ll * a * a % 1000000007;
    b = b >> 1;
  }
  return res;
}
int ans;
int rans = 0;
int fac[100010];
void solve(int st, int mxl) {
  if (st == 0) {
    if (mxl == 1) ans = 0;
    if (mxl == 2) ans = 1;
    rans = (rans + ans) % 1000000007;
    return;
  }
  int lowbit = st & (-st);
  for (int i = st; i != 0; i = (i - 1) & st) {
    if (!(i & lowbit)) continue;
    int v = sl[i], tans = ans;
    ans = 1ll * ans * inv[v][ccnt[v]] % 1000000007;
    ++ccnt[v];
    ans = 1ll * ans * f[v][ccnt[v]] % 1000000007 * fac[bitcnt[i] - 1] %
          1000000007;
    solve(st ^ i, max(mxl, v));
    ans = tans;
    --ccnt[v];
  }
  return;
}
int main() {
  scanf("%d%d", &n, &k);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % 1000000007;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), ++ind[a[i]];
  for (int i = 1; i <= n; ++i) {
    f[i].push_back(1);
    inv[i].push_back(1);
    f[i].push_back(i);
    inv[i].push_back(power(i, 1000000007 - 2));
    for (int j = 2; j <= n / i; ++j) {
      f[i].push_back(
          (1ll * i * f[i][j - 1] % 1000000007 +
           1ll * i * (j - 1) % 1000000007 * f[i][j - 2] % 1000000007) %
          1000000007);
      inv[i].push_back(power(f[i][j], 1000000007 - 2));
    }
  }
  for (int i = 1; i <= n; ++i)
    if (ind[i] == 0) dfs(i, 0);
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i, 0);
  int tot = (1 << cc) - 1;
  int mxl = 0;
  for (int i = 1; i <= n; ++i)
    if (ccnt[i]) mxl = i;
  for (int i = 1; i <= tot; ++i) {
    bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    for (int j = 1; j <= cc; ++j)
      if ((i >> (j - 1)) & 1) sl[i] += cl[j];
  }
  ans = 1;
  for (int i = 1; i <= n; ++i) ans = 1ll * ans * f[i][ccnt[i]] % 1000000007;
  solve(tot, mxl);
  cout << rans << endl;
  return 0;
}
