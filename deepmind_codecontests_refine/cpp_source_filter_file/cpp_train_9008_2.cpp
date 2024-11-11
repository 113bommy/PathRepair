#include <bits/stdc++.h>
using namespace std;
const int N = 111111;
int n;
vector<int> g[N];
int sz[N];
void dfsz(int v, int p) {
  sz[v] = 1;
  for (int to : g[v]) {
    if (to != p) {
      dfsz(to, v);
      sz[v] += sz[to];
    }
  }
}
double ans[N];
void bfs() {
  queue<int> q;
  vector<int> used(n, false);
  q.push(1);
  used[1] = true;
  ans[1] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (used[v]) continue;
      ans[v] = ans[u] + 1.0 + (sz[u] - sz[v] - 1) / 2.0;
      used[v] = true;
      q.push(v);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int v = 2; v <= n; v++) {
    int p;
    scanf("%d", &p);
    g[v].push_back(p);
    g[p].push_back(v);
  }
  dfsz(1, -1);
  bfs();
  for (int v = 1; v <= n; v++) {
    printf("%.10lf ", ans[v]);
  }
  printf("\n");
  return 0;
}
