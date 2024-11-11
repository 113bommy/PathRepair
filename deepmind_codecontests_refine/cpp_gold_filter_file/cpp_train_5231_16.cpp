#include <bits/stdc++.h>
using namespace std;
const int base = 37, mod = 998244353;
int n, q, lim, cnt;
int a[19];
bool vis[1 << 18][19];
char s[20][20], t[20];
unsigned long long f[1 << 18][19], g[2][1 << 18], G[400], F[19][1 << 18],
    res[1 << 18];
map<int, int> mp;
void FWT(unsigned long long *, int);
void dfs(int, int, int);
int main() {
  scanf("%d", &n);
  lim = 1 << n;
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  queue<pair<int, int> > Q;
  for (int i = 1; i <= n; ++i) {
    Q.push(make_pair(1 << (i - 1), i));
    f[1 << (i - 1)][i] = 1;
  }
  while (!Q.empty()) {
    int S = Q.front().first, u = Q.front().second;
    Q.pop();
    int cnt = 0;
    for (int i = 1; i <= n; ++i) cnt += (S >> (i - 1)) & 1;
    for (int i = 1; i <= n; ++i)
      if (s[u][i] == '1' && !((S >> (i - 1)) & 1)) {
        int s = S ^ (1 << (i - 1));
        f[s][i] += f[S][u];
        if (!vis[s][i]) Q.push(make_pair(s, i)), vis[s][i] = true;
      }
  }
  for (int i = 0; i < lim; ++i) {
    int cnt = 0;
    unsigned long long sum = 0;
    for (int j = 1; j <= n; ++j) {
      if (i & (1 << (j - 1))) ++cnt;
      sum += f[i][j];
    }
    F[cnt][i] = sum;
  }
  for (int i = 1; i <= n; ++i) FWT(F[i], 1);
  g[0][0] = 1;
  FWT(g[0], 1);
  dfs(n, 1, 0);
  int all = 1 << (n - 1);
  for (int i = 0; i < all; ++i) {
    int num = 0;
    for (int j = 1; j <= n; ++j) {
      if (!((i >> (j - 1)) & 1)) {
        a[++num] = 1;
        continue;
      }
      int pos = j;
      while ((i >> (pos - 1)) & 1 && pos < n) ++pos;
      a[++num] = pos - j + 1;
      j = pos;
    }
    sort(a + 1, a + 1 + num);
    int hs = 0;
    for (int j = 1; j <= num; ++j) hs = (1ll * hs * base + a[j]) % mod;
    int id = mp[hs];
    res[i ^ (all - 1)] = G[id];
  }
  FWT(res, -1);
  for (int i = 0; i < all; ++i) printf("%lld ", res[i ^ (all - 1)]);
  return 0;
}
void FWT(unsigned long long *x, int flag) {
  for (int i = 1; i < lim; i <<= 1)
    for (int j = 0; j < lim; j += i << 1)
      for (int k = j; k < i + j; ++k) x[i + k] += flag * x[k];
  return;
}
void dfs(int u, int lst, int c) {
  if (!u) {
    int hs = 0;
    for (int i = 1; i <= c; ++i) hs = (1ll * hs * base + a[i]) % mod;
    mp[hs] = ++cnt;
    memcpy(g[1], g[0], sizeof g[1]);
    for (int i = 1; i <= c; ++i)
      for (int j = 0; j < lim; ++j) g[1][j] *= F[a[i]][j];
    FWT(g[1], -1);
    G[cnt] = g[1][lim - 1];
    return;
  }
  for (int i = lst; i <= u; ++i) {
    a[c + 1] = i;
    dfs(u - i, i, c + 1);
  }
  return;
}
