#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct EDGE {
  int to, next, id;
  EDGE(int to = 0, int next = 0, int id = 0) : to(to), next(next), id(id) {}
} edge[maxn * 2];
int head[maxn], edgecnt;
int ansu[maxn], ansv[maxn];
double anst[maxn];
void init() {
  memset(head, -1, sizeof(head));
  edgecnt = 0;
}
void add(int u, int v, int id) {
  edge[edgecnt] = EDGE(v, head[u], id);
  head[u] = edgecnt++;
}
void dfs(int u, int fa, double t) {
  int deg = 0;
  for (int i = head[u]; ~i; i = edge[i].next) deg++;
  for (int i = head[u]; ~i; i = edge[i].next) {
    int v = edge[i].to;
    int id = edge[i].id;
    if (v != fa) {
      t += 2.0 / deg;
      if (t >= 2.0) t -= 2.0;
      if (t < 1) {
        ansu[id] = v;
        ansv[id] = u;
        anst[id] = t;
      } else {
        ansu[id] = u;
        ansv[id] = v;
        anst[id] = t - 1;
      }
      dfs(v, u, t + 1);
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    add(u, v, i);
    add(v, u, i);
  }
  dfs(1, 0, 0);
  printf("%d\n", n - 1);
  for (int i = 0; i < n; i += 2) {
    int id = edge[i].id;
    printf("%d %d %d %d %.12f\n", 1, id, ansu[id], ansv[id], anst[id]);
  }
  return 0;
}
