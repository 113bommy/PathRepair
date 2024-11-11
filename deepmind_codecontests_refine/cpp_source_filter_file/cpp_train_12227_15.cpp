#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
const int INF = 0x3fffffff;
int n, m, x[505], a[505 * 505], b[505 * 505], c[505 * 505];
double ans;
long long V, E;
int head[505], cnt;
struct Edge {
  int v, c, next;
} p[505 * 505 * 2];
void init() {
  memset(p, 0, sizeof(p));
  fill(head, head + 505, -1);
  cnt = 0;
}
void addEdge(int u, int v, int c) {
  p[cnt].v = v;
  p[cnt].c = c;
  p[cnt].next = head[u];
  head[u] = cnt++;
}
void dfs(int u) {}
void work() {
  init();
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &a[i], &b[i], &c[i]);
    addEdge(a[i], b[i], c[i]);
    addEdge(b[i], a[i], c[i]);
  }
  if (m == 0) {
    printf("%.9lf\n", 0.0);
    return;
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    long long V = x[a[i]] + x[b[i]];
    long long E = c[i];
    ans = Max(ans, (double)V / (double)E);
  }
  printf("%.9lf\n", ans);
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    work();
  }
  return 0;
}
