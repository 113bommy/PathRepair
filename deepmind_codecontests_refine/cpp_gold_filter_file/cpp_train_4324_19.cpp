#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200004], ans[200004];
int clr[200004], mx = 0;
map<int, map<int, int> > mp;
void bfs(int src) {
  int u, v, p, q, r, sz;
  queue<int> qu;
  qu.push(src);
  while (!qu.empty()) {
    u = qu.front();
    qu.pop();
    sz = adj[u].size();
    p = 0;
    for (int lp = 0; lp < sz; lp++) {
      v = adj[u][lp];
      if (clr[v] == 0) {
        p++;
        if (p == clr[u]) p++;
        if (p > mx) mx = p;
        ans[p].push_back(mp[u][v]);
        qu.push(v);
        clr[v] = p;
      }
    }
  }
}
int main() {
  int n, m, a, b, c, d, i, j;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    mp[a][b] = i;
    mp[b][a] = i;
  }
  clr[1] = -1;
  bfs(1);
  printf("%d\n", mx);
  for (i = 1; i <= mx; i++) {
    d = ans[i].size();
    printf("%d ", d);
    for (j = 0; j < d; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }
  return 0;
}
