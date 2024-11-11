#include <bits/stdc++.h>
using namespace std;
int ask(char type, int id) {
  printf("%c %d\n", type, id);
  fflush(stdout);
  int q = -1;
  if (type != 'C') scanf("%d", &q);
  return q;
}
vector<int> g[1010];
int x[1010], y[1010], par[1010];
bool apr_x[1010], apr_y[1010];
void solve() {
  int n, a, b;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    apr_x[i] = apr_y[i] = true;
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int k1, k2;
  scanf("%d", &k1);
  for (int i = 1; i <= k1; i++) {
    scanf("%d", x + i);
    apr_x[x[i]] = true;
  }
  scanf("%d", &k2);
  for (int i = 1; i <= k2; i++) {
    scanf("%d", y + i);
    apr_y[y[i]] = true;
  }
  int x_id = ask('B', y[1]);
  queue<int> q;
  q.push(x_id);
  par[x_id] = -1;
  int found = -1;
  while (!q.empty()) {
    int u = q.front();
    if (apr_x[u]) {
      found = u;
      break;
    }
    q.pop();
    for (int i = 0; i < (int)g[u].size(); i++) {
      int v = g[u][i];
      if (v != par[u]) {
        par[v] = u;
        q.push(v);
      }
    }
  }
  int y_id = ask('A', found);
  if (apr_y[y_id])
    ask('C', found);
  else
    ask('C', -1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
