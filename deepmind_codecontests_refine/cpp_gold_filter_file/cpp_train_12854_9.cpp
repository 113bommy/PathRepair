#include <bits/stdc++.h>
using namespace std;
const int mxn = 2e5 + 5;
vector<int> g[mxn], v[mxn];
int n, m, ans;
int dfn[mxn], low[mxn], bel[mxn], cnt, c2;
struct Stack {
  int sta[mxn], Top;
  inline void init() {
    memset(sta, 0, sizeof(sta));
    Top = 0;
  }
  inline void push(int x) { sta[++Top] = x; }
  inline int top() { return sta[Top]; }
  inline void pop() { --Top; }
} s;
inline void tarjin(int x, int pa = -1) {
  dfn[x] = low[x] = ++cnt;
  s.push(x);
  for (int y : g[x]) {
    if (y != pa) {
      if (!dfn[y]) tarjin(y, x);
      low[x] = min(low[x], low[y]);
    }
  }
  if (low[x] == dfn[x]) {
    ++c2;
    for (; s.top() != x;) bel[s.top()] = c2, s.pop();
    bel[s.top()] = c2;
    s.pop();
  }
}
bool vis[mxn];
int D;
inline int dfs(int x, int pa = -1) {
  if (v[x].size() < 2) --ans;
  vis[x] = 1;
  int tmp[3];
  memset(tmp, 0, sizeof(tmp));
  for (int y : v[x]) {
    if (y == pa) continue;
    tmp[0] = dfs(y, x);
    sort(tmp, tmp + 3);
    D = max(tmp[1] + tmp[2], D);
  }
  return tmp[2] + 1;
}
inline void solve() {
  s.init();
  cin >> n >> m;
  ans = n - 1;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) tarjin(i);
  for (int i = 1; i <= n; ++i)
    for (int j : g[i])
      if (bel[i] != bel[j]) v[bel[i]].push_back(bel[j]);
  for (int i = 1; i <= c2; ++i) {
    if (!vis[i]) {
      D = 0;
      dfs(i);
      ans -= (D == 0) ? (-1) : (D - 2);
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int T = 1;
  for (; T--;) solve();
}
