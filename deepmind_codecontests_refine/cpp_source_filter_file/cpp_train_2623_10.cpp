#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a, b, k;
double sumx, sumy, ans;
int head[N], size[N];
double x[N], y[N];
struct edge {
  int v, next;
} e[N << 1];
inline void add(int u, int v) {
  e[++k] = (edge){v, head[u]};
  head[u] = k;
}
void DFS(int u, int fa) {
  size[u] = 1;
  for (register int i = head[u]; i; i = e[i].next)
    if (e[i].v != fa) {
      DFS(e[i].v, u);
      size[u] += size[e[i].v];
      x[u] += x[e[i].v];
      ans += x[e[i].v] * size[e[i].v] * y[u];
    }
  ans += (sumx - x[u]) * (n - size[u]) * y[u];
}
int main(void) {
  scanf("%d", &n);
  for (register int i = 1; i < n; ++i) {
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }
  for (register int i = 1; i <= n; ++i) {
    scanf("%lf%lf", x + i, y + i);
    sumx += x[i], sumy += y[i];
  }
  DFS(1, 0);
  printf("%lf\n", ans / sumx / sumy);
  return 0;
}
