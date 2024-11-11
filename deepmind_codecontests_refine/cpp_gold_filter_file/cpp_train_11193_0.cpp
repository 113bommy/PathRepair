#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 7;
int n, d[maxN], sz;
vector<int> g[maxN];
void dfs(int v, int depth = 0, int pr = -1) {
  bool isLeaf = true;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == pr) continue;
    isLeaf = false;
    dfs(to, depth + 1, v);
  }
  if (isLeaf) {
    d[sz++] = depth;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int res = 0;
  for (int i = 0; i < g[1].size(); ++i) {
    sz = 0;
    dfs(g[1][i], 0, 1);
    sort(d, d + sz);
    int now = d[0];
    for (int i = 1; i < sz; ++i) {
      now = max(now + 1, d[i]);
    }
    res = max(res, now + 1);
  }
  cout << res << "\n";
  return 0;
}
