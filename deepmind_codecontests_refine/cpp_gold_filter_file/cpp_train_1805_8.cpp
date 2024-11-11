#include <bits/stdc++.h>
using namespace std;
bool ind[100009];
queue<int> q;
int dis[100009], fl[100009], S, T, sa, ans;
int n, K, idx, hd[100009], cnt, rk[100009], fr[100009];
struct TASK {
  int l, r, c;
} tas[100009];
struct SEP {
  int a, i, l;
} a[100009];
struct Edge {
  int to, nxt, f, w;
} edge[100009 << 1];
int read();
bool cmp(SEP x, SEP y) { return x.a < y.a; }
void add(int u, int v, int f, int w) {
  edge[++cnt] = (Edge){v, hd[u], f, w};
  hd[u] = cnt;
  edge[++cnt] = (Edge){u, hd[v], 0, -w};
  hd[v] = cnt;
}
bool SPFA() {
  for (int i = 1; i <= idx; ++i) dis[i] = 0x3f3f3f3f;
  dis[S] = 0;
  q.push(S);
  ind[S] = true;
  fl[S] = 0x3f3f3f3f;
  while (q.size()) {
    int u = q.front();
    q.pop();
    ind[u] = false;
    for (int i = hd[u], v; i; i = edge[i].nxt)
      if (edge[i].f && dis[v = edge[i].to] > dis[u] + edge[i].w) {
        if (!ind[v]) ind[v] = true, q.push(v);
        fr[v] = 1 + (i - 1 ^ 1);
        dis[v] = dis[u] + edge[i].w;
        fl[v] = (fl[u]) < (edge[i].f) ? (fl[u]) : (edge[i].f);
      }
  }
  return dis[T] < 0x3f3f3f3f;
}
void dfs(int u) {
  if (u == S) return;
  int i = fr[u];
  edge[1 + (i - 1 ^ 1)].f -= fl[T];
  edge[i].f += fl[T];
  dfs(edge[i].to);
}
int main() {
  n = read(), K = read();
  for (int i = 1; i <= n; ++i) {
    tas[i].l = read(), tas[i].r = read(), tas[i].c = read();
    tas[i].r += tas[i].l;
    a[++sa] = (SEP){tas[i].l, i, 0};
    a[++sa] = (SEP){tas[i].r, i, 1};
  }
  sort(a + 1, a + 1 + sa, cmp);
  a[0].a = -10;
  for (int i = 1; i <= sa; ++i)
    if (a[i].l)
      tas[a[i].i].r = (idx += a[i].a != a[i - 1].a);
    else
      tas[a[i].i].l = (idx += a[i].a != a[i - 1].a);
  for (int i = 1; i < idx; ++i) add(i, i + 1, K, 0);
  S = ++idx;
  T = ++idx;
  add(S, 1, K, 0);
  add(idx - 2, T, K, 0);
  for (int i = 1; i <= n; ++i) {
    rk[i] = cnt + 1;
    add(tas[i].l, tas[i].r, 1, -tas[i].c);
  }
  while (SPFA()) ans += dis[T] * fl[T], dfs(T);
  for (int i = 1; i <= n; ++i) edge[rk[i]].f ? printf("0 ") : printf("1 ");
  puts("");
  return 0;
}
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') f = (c == '-') ? -1 : f, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
