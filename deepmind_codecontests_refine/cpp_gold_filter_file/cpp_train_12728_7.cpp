#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int P = 998244353;
const int inf = 0x3f3f3f3f;
bitset<maxn> is[10][10];
int n, m, k, c[10], ans, vis[maxn], s[maxn], cnt[10][10], jd[10][10][10][10];
vector<pair<int, int>> G[maxn];
inline int read() {
  char ch = getchar();
  int u = 0, f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    u = u * 10 + ch - 48;
    ch = getchar();
  }
  return u * f;
}
inline bool ok(int a, int b) {
  for (int i = 1; i <= a - 1; ++i)
    if (jd[a][b][i][c[i]]) return false;
  return true;
}
inline int dfs(int x, int num, int rnt = 0) {
  if (x == k + 1) return num == n;
  for (int i = 1; i <= x; ++i) {
    if (ok(x, i)) {
      c[x] = i;
      rnt += dfs(x + 1, num + cnt[x][i]);
    }
  }
  return rnt;
}
int main() {
  n = read();
  m = read();
  k = read();
  for (int i = 1; i <= m; ++i) {
    int x = read(), y = read(), w = read();
    G[x].push_back(make_pair(w, y));
  }
  for (int i = 1; i <= n; ++i) {
    sort(G[i].begin(), G[i].end());
    s[i] = ((int)G[i].size());
    for (int j = 1; j <= s[i]; ++j) is[s[i]][j].set(G[i][j - 1].second);
  }
  for (int i = 1; i <= k; ++i)
    for (int j = 1; j <= i; ++j) cnt[i][j] = is[i][j].count();
  for (int a = 1; a <= k; ++a)
    for (int b = 1; b <= a; ++b)
      for (int c = 1; c <= k; ++c)
        for (int d = 1; d <= c; ++d)
          if ((is[a][b] & is[c][d]).count()) jd[a][b][c][d] = 1;
  cout << dfs(1, 0) << endl;
  return 0;
}
