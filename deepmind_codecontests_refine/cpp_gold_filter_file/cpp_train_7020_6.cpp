#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> st, goal;
vector<int> ans;
void dfs(int v, int h = 0, int odd = 0, int even = 0, int p = -1) {
  if (h % 2 == 0) {
    if (odd) st[v] = 1 - st[v];
  } else if (even)
    st[v] = 1 - st[v];
  if (st[v] != goal[v]) {
    ans.push_back(v);
    if (h % 2 == 0)
      odd = 1 - odd;
    else
      even = 1 - even;
  }
  for (int i = 0; i < g[v].size(); i++) {
    int u = g[v][i];
    if (u != p) {
      dfs(u, h + 1, odd, even, v);
    }
  }
}
int main(void) {
  int n;
  scanf("%d", &n);
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    st.push_back(x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    goal.push_back(x);
  }
  dfs(0);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i] + 1);
  return 0;
}
