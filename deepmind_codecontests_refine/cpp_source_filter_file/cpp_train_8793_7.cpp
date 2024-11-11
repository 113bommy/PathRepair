#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[100010];
bool vis[100010];
queue<int> q;
int bfs() {
  q.push(n);
  memset(d, 0x3f, sizeof(d));
  d[n] = 0;
  vis[n] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    if (u == m) return d[u];
    int nxtB = u << 1;
    int nxtR = u - 1;
    if (u < n && d[u] + 1 < d[nxtB]) {
      d[nxtB] = d[u] + 1;
      if (!vis[nxtB]) q.push(nxtB), vis[nxtB] = 1;
    }
    if (nxtR > 0 && d[u] + 1 < d[nxtR]) {
      d[nxtR] = d[u] + 1;
      if (!vis[nxtR]) q.push(nxtR), vis[nxtR] = 1;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  printf("%d\n", bfs());
}
