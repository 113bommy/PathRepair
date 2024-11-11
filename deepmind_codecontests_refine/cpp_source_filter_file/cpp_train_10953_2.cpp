#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 1e6 + 3;
void rd(int &x) {
  int f = 1;
  x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
void pr(int x) { printf("%d\n", x); }
pair<pair<int, int>, int> pa[5005];
vector<pair<int, int> > g[5005];
int eg[5005];
bool dfs(int fa, int s, int t, int w) {
  bool bj = 0;
  if (s == t) return 1;
  for (auto u : g[s]) {
    int x = u.first;
    if (x != fa)
      if (dfs(s, x, t, w)) eg[u.second] = max(eg[u.second], w), bj = 1;
  }
  return bj;
}
bool check(int fa, int s, int t, int &ans) {
  bool bj = 0;
  if (s == t) return 1;
  for (auto u : g[s]) {
    int x = u.first;
    if (x != fa)
      if (check(s, x, t, ans)) ans = min(eg[u.second], ans), bj = 1;
  }
  return bj;
}
int main() {
  int n, m;
  rd(n);
  for (int i = (0); i < n - 1; i++) {
    int a, b;
    rd(a), rd(b);
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  rd(m);
  for (int i = (0); i < m; i++) {
    int a, b, c;
    rd(a), rd(b), rd(c);
    pa[i] = {{a, b}, c};
    dfs(0, a, b, c);
  }
  for (int i = (0); i < m; i++) {
    int ans = 0x3f3f3f3f;
    int s = pa[i].first.first, t = pa[i].first.second, w = pa[i].second;
    check(0, s, t, ans);
    if (ans != w) return 0 * puts("-1");
  }
  for (int i = (0); i < n - 1; i++) {
    if (eg[i])
      printf("%d ", eg[i]);
    else
      printf("1");
  }
}
