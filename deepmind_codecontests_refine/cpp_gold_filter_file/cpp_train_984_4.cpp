#include <bits/stdc++.h>
using namespace std;
vector<int> conn[105];
int mark[105];
void dfs(int u, int c) {
  mark[u] = true;
  int sz = conn[u].size();
  for (int i = 0; i < sz; i += 2) {
    int v = conn[u][i], x = conn[u][i + 1];
    if (!mark[v] and x == c) dfs(v, c);
  }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    conn[a].push_back(b);
    conn[a].push_back(c);
    conn[b].push_back(a);
    conn[b].push_back(c);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      memset(mark, 0, sizeof mark);
      dfs(u, i);
      if (mark[v]) res++;
    }
    printf("%d\n", res);
  }
}
