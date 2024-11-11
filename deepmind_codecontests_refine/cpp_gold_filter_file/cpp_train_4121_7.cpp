#include <bits/stdc++.h>
using namespace std;
void Read(int &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
void Read(long long int &x) {
  x = 0;
  char c = getchar();
  bool flag = 0;
  while (c < '0' || '9' < c) {
    if (c == '-') flag = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (flag) x = -x;
}
struct node {
  int v;
  node *nxt;
} * adj[30 + 10], Edges[30 * 2 + 10], *New = Edges;
void addedge(int u, int v) {
  node *p = ++New;
  p->v = v;
  p->nxt = adj[u];
  adj[u] = p;
}
const int tmp[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
int d[30 + 10];
long long int x[30 + 10], y[30 + 10];
int N;
void dfs(int now, int fa, int dir, long long int px, long long int py,
         long long int len) {
  x[now] = px, y[now] = py;
  long long int tlen = len >> 1;
  int td = 0;
  for (node *p = adj[now]; p != NULL; p = p->nxt)
    if (p->v != fa) {
      if (td == dir) ++td;
      dfs(p->v, now, 3 - td, px + tmp[td][0] * (tlen >> 1),
          py + tmp[td][1] * (tlen >> 1), tlen);
      ++td;
    }
}
int main() {
  Read(N);
  int u, v;
  for (int i = 1; i < N; ++i) {
    Read(u), Read(v);
    ++d[u], ++d[v];
    addedge(u, v), addedge(v, u);
  }
  for (int i = 1; i <= N; ++i)
    if (d[i] > 4) {
      puts("NO");
      return 0;
    }
  puts("YES");
  dfs(1, -1, -1, 0ll, 0ll, 1e18);
  for (int i = 1; i <= N; ++i) printf("%I64d %I64d\n", x[i], y[i]);
}
