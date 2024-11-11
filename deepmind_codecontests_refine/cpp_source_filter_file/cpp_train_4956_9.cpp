#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
const int inf = 0x3f3f3f3f;
int x[N], y[N], d[N], q[N];
bool vis[N];
int spfa(int s, int t, int n) {
  for (int i = 1; i <= n; i++) d[i] = inf;
  d[s] = 0;
  vis[s] = false;
  int head = 0, tail = 0;
  q[tail++] = s;
  while (head < tail) {
    int u = q[head++];
    if (head == N) head = 0;
    vis[u] = false;
    for (int v = 1; v <= n; v++) {
      int w = inf;
      int dx = (x[v] - x[u] > 0) ? x[v] - x[u] : x[u] - x[v];
      int dy = (y[v] - y[u] > 0) ? y[v] - y[u] : y[u] - y[v];
      if (dx + dy <= 1)
        w = 0;
      else if ((dx <= 2) || (dy <= 2))
        w = 1;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        if (!vis[v]) {
          vis[v] = true;
          q[tail++] = v;
          if (tail == N) tail = 0;
        }
      }
    }
  }
  if (d[n] == inf)
    return -1;
  else
    return d[n];
}
int main() {
  int s, t, n, m, k;
  bool flag = false;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x[i], &y[i]);
    if ((x[i] == 1) && (y[i] == 1))
      s = i;
    else if ((x[i] == n) && (y[i] == m))
      flag = true;
  }
  if (flag == false) x[++k] = n + 1, y[k] = m + 1;
  printf("%d\n", spfa(s, k, k));
  return 0;
}
