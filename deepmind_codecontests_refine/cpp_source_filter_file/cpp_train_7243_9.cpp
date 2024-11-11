#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void next_int(T &x) {
  x = 0;
  char c;
  bool neg = false;
  while (!isdigit(c = getchar()))
    if (c == '-') neg = true;
  do x = x * 10 + c - 48;
  while (isdigit(c = getchar()));
  if (neg) x = -x;
}
template <typename T>
inline void write_int(T x, char last = 0) {
  if (x < 0) putchar('-'), x = abs(x);
  char tmp[20];
  int cnt = 0;
  while (x >= 10) tmp[cnt++] = x % 10 + 48, x /= 10;
  tmp[cnt] = x + 48;
  for (int i = (cnt); i >= (0); --i) putchar(tmp[i]);
  if (last) putchar(last);
}
const int base = 31;
int mod[2] = {(int)1e9 + 7, (int)1e9 + 9};
const int N = (int)3e5 + 5;
int n, dep[N], sz[N], ans[N], pos[N];
int h[2][N], pw[2][N];
set<pair<int, int> > s[N];
vector<vector<pair<int, int> > > g;
void dfs_prep(int u, int p) {
  sz[u] = 1, pos[u] = u;
  for (int i = (0); i < (((int)g[u].size())); ++i) {
    int v = g[u][i].first, c = g[u][i].second;
    if (v == p) continue;
    dep[v] = dep[u] + 1;
    for (int j = (0); j < (2); ++j)
      h[j][v] = (h[j][u] + 1LL * c * pw[j][dep[u]]) % mod[j];
    dfs_prep(v, u);
    sz[u] += sz[v];
  }
}
void dfs_calc(int u, int p) {
  int maxv = -1, cmaxv = -1;
  for (int i = (0); i < (((int)g[u].size())); ++i) {
    int v = g[u][i].first;
    if (v == p) continue;
    dfs_calc(v, u);
    if (maxv == -1 || sz[maxv] < sz[v]) maxv = v, cmaxv = g[u][i].second;
  }
  if (maxv != -1) pos[u] = pos[maxv];
  set<pair<int, int> > s2;
  int cnt = 0;
  for (int i = (0); i < (((int)g[u].size())); ++i) {
    int v = g[u][i].first, c = g[u][i].second;
    if (v == p || v == maxv) continue;
    for (auto it : s[pos[v]]) {
      pair<int, int> tmp;
      tmp.first = (it.first + 1LL * (cmaxv - c) * pw[0][dep[u]]) % mod[0];
      if (tmp.first < 0) tmp.first += mod[0];
      tmp.second = (it.second + 1LL * (cmaxv - c) * pw[1][dep[u]]) % mod[1];
      if (tmp.second < 0) tmp.second += mod[1];
      if (s[pos[u]].find(tmp) != s[pos[u]].end() || s2.find(tmp) != s2.end())
        ++cnt;
      s2.insert(tmp), s[pos[u]].insert(it);
    }
  }
  if (maxv != -1) ans[dep[u] + 1] += (cnt + 1);
  s[pos[u]].insert(pair<int, int>(h[0][u], h[1][u]));
}
int main() {
  next_int(n);
  g.resize(n + 1);
  for (int i = (1); i < (n); ++i) {
    int u, v;
    char c;
    next_int(u), next_int(v);
    c = getchar();
    while (!(c >= 'a' && c <= 'z')) c = getchar();
    g[u].push_back(pair<int, int>(v, c - 'a'));
    g[v].push_back(pair<int, int>(u, c - 'a'));
  }
  pw[0][0] = pw[1][0] = 1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (0); j < (2); ++j)
      pw[j][i] = 1LL * pw[j][i - 1] * base % mod[j];
  dfs_prep(1, 0);
  dfs_calc(1, 0);
  int res = -1, resid = 0;
  for (int i = (1); i <= (n); ++i) {
    if (res == -1 || res > n - ans[i]) res = n - ans[i], resid = i;
  }
  write_int(res, '\n'), write_int(resid);
  return 0;
}
