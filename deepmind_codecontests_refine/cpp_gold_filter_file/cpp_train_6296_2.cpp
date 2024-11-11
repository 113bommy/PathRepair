#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int head[N], nxt[N], ver[N], cnt, tot, n, m, deg[N];
bool vis[N];
vector<int> t;
void add(int x, int y) {
  ver[++tot] = y;
  nxt[tot] = head[x];
  head[x] = tot;
  ver[++tot] = x;
  nxt[tot] = head[y];
  head[y] = tot;
}
void dfs(int x) {
  for (int &i = head[x]; i; i = nxt[i]) {
    if (vis[i]) continue;
    int y = ver[i];
    vis[i] = vis[i ^ 1] = 1;
    dfs(y);
    if ((++cnt) % 2)
      cout << x << ' ' << y << '\n';
    else
      cout << y << ' ' << x << '\n';
  }
}
signed main() {
  tot = 1;
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> n >> m;
  for (register int i = (1); i <= (m); ++i) {
    cin >> x >> y;
    deg[x]++;
    deg[y]++;
    add(x, y);
  }
  for (register int i = (1); i <= (n); ++i)
    if (deg[i] % 2) t.push_back(i);
  for (register int i = (1); i <= (t.size()); ++i)
    if (i % 2) add(t[i - 1], t[i]), m++;
  if (m & 1) add(1, 1), m++;
  cout << m << '\n';
  dfs(1);
  return 0;
}
