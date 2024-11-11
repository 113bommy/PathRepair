#include <bits/stdc++.h>
using namespace std;
const int _ = 2e5 + 5, yl = 1e9 + 7;
int n, rt, siz[_], ch[3][_], f[_], g[_], d[_], cnt;
vector<int> e[_];
long long F(int x);
long long G(int x, int y);
long long F(int x) {
  if (x == 0) return 1;
  if (siz[x] & 1) return 0;
  if (!g[x]) return siz[x] / 2;
  if (f[x] != -1) return f[x];
  long long ans = 0, y = g[x], lc = ch[0][y], rc = ch[1][y];
  for (int i = 0; i <= 1; ++i, swap(lc, rc)) {
    int p = ch[0][rc], q = ch[1][rc];
    if (!q) {
      if (p) ans += G(lc, p);
      if (!g[rc] && d[rc] <= d[x]) ans += F(lc) * (d[x] == d[rc] ? 1 : 2);
    } else {
      if (!g[p] && d[p] <= d[x]) ans += G(lc, q);
      if (!g[q] && d[q] <= d[x]) ans += G(lc, p);
    }
  }
  return f[x] = ans % yl;
}
long long G(int x, int y) {
  if (x == 0 || y == 0) return F(x + y);
  if ((siz[x] + siz[y]) & 1) return 0;
  if (e[x].size() == 2 && e[y].size() == 2) return G(ch[0][x], ch[0][y]);
  if (e[x].size() == 1 && e[y].size() == 1) return 1;
  if (e[x].size() == 1 && e[y].size() == 2) return F(ch[0][y]);
  if (e[x].size() == 2 && e[y].size() == 1) return F(ch[0][x]);
  return 0;
}
long long solve() {
  long long ans = 0, k;
  memset(f, -1, sizeof(f));
  k = ch[2][rt];
  ans += G(ch[0][rt], ch[0][k]) * G(ch[1][rt], ch[1][k]) % yl;
  if (e[k].size() > 1)
    ans += G(ch[0][rt], ch[1][k]) * G(ch[1][rt], ch[0][k]) % yl;
  k = ch[1][rt];
  ans += G(ch[0][rt], ch[0][k]) * G(ch[2][rt], ch[1][k]) % yl;
  if (e[k].size() > 1)
    ans += G(ch[0][rt], ch[1][k]) * G(ch[2][rt], ch[0][k]) % yl;
  k = ch[0][rt];
  ans += G(ch[1][rt], ch[0][k]) * G(ch[2][rt], ch[1][k]) % yl;
  if (e[k].size() > 1)
    ans += G(ch[1][rt], ch[1][k]) * G(ch[2][rt], ch[0][k]) % yl;
  return ans * 4 % yl;
}
void dfs(int fa, int u) {
  int s = 0;
  siz[u] = 1;
  for (int v : e[u]) {
    if (v == fa) continue;
    dfs(u, v);
    ch[s++][u] = v;
    siz[u] += siz[v];
    g[u] = g[v];
    d[u] = d[v] + 1;
  }
  if (e[u].size() == 3) g[u] = u, d[u] = 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  if (n == 1) cout << 2 << endl, exit(0);
  for (int i = 1; i < (n << 1); ++i) {
    int u, v;
    cin >> u >> v;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for (int i = 1; i < (n << 1); ++i) {
    if (e[i].size() > 3) cout << 0 << endl, exit(0);
    if (e[i].size() == 3) rt = i;
  }
  if (rt == 0) cout << (2ll * n * n - n * 2 + 4) % yl << endl, exit(0);
  dfs(0, rt);
  cout << solve() << endl;
  return 0;
}
