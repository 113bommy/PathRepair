#include <bits/stdc++.h>
using namespace std;
const int mxn = (2e5) + 5;
vector<pair<int, int> > tr[mxn];
vector<int> ans[mxn];
int mx;
void dfs(int v, int p, int in) {
  mx = max(mx, in);
  int c = -1;
  for (int i = 0; i < tr[v].size(); ++i) {
    int u = tr[v][i].first;
    int x = tr[v][i].second;
    if (u == p) continue;
    ++c;
    if (c == in) ++c;
    ans[c].push_back(x);
    dfs(u, v, c);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    tr[x].push_back({y, i + 1});
    tr[y].push_back({x, i + 1});
  }
  dfs(1, 1, -1);
  printf("%d\n", mx);
  for (int i = 0; !ans[i].empty(); ++i) {
    printf("%d", ans[i].size());
    for (int j = 0; j < ans[i].size(); ++j) printf(" %d", ans[i][j]);
    puts("");
  }
  return 0;
}
