#include <bits/stdc++.h>
using namespace std;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}
inline void read(int &x) {
  char c = nc(), b = 1;
  for (; !(c >= '0' && c <= '9'); c = nc())
    if (c == '-') b = -1;
  for (x = 0; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
  x *= b;
}
const int N = 1000005;
struct edge {
  int u, v, idx, next;
} G[N << 1];
int head[N], inum = 1;
inline void add(int u, int v, int idx, int p) {
  G[p].u = u;
  G[p].v = v;
  G[p].idx = idx;
  G[p].next = head[u];
  head[u] = p;
}
int n, m;
int vst[N], depth[N];
int tag[N], cnt, tmp;
int cir, totc;
void dfs(int u, int fa) {
  vst[u] = 1;
  for (int p = head[u]; p; p = G[p].next)
    if (p != (fa ^ 1))
      if (!vst[G[p].v])
        depth[G[p].v] = depth[u] + 1, dfs(G[p].v, p), tag[u] += tag[G[p].v];
      else {
        if (depth[G[p].v] > depth[u]) continue;
        if ((depth[u] - depth[G[p].v] + 1) & 1)
          tag[u]++, tag[G[p].v]--, cnt++, tmp = G[p].idx;
        else
          tag[u]--, tag[G[p].v]++;
      }
}
int ans[N], tot, cur;
inline void find(int u, int fa) {
  vst[u] = 1;
  if (tag[u] == cnt) ans[++tot] = G[fa].idx;
  for (int p = head[u]; p; p = G[p].next)
    if (!vst[G[p].v]) find(G[p].v, p);
}
int main() {
  int iu, iv;
  read(n);
  read(m);
  for (int i = 1; i <= m; i++) {
    read(iu), read(iv);
    if (iu == iv)
      cir = i, totc++;
    else
      add(iu, iv, i, ++inum), add(iv, iu, i, ++inum);
  }
  for (int i = 1; i <= n; i++)
    if (!vst[i]) depth[i] = 1, dfs(i, 0);
  if (cnt == 0) {
    if (totc) {
      if (totc == 1)
        printf("1\n%d\n", cir);
      else
        printf("0\n");
    } else {
      printf("%d\n", m);
      for (int i = 1; i <= m; i++) printf("%d%c", i, i == m ? '\n' : ' ');
    }
    return 0;
  }
  if (totc) return printf("0\n"), 0;
  memset(vst, 0, sizeof(vst));
  for (int i = 1; i <= n; i++)
    if (!vst[i]) find(1, 0);
  if (cnt == 1) ans[++tot] = tmp;
  sort(ans + 1, ans + tot + 1);
  printf("%d\n", tot);
  for (int i = 1; i <= tot; i++) printf("%d%c", ans[i], i == tot ? '\n' : ' ');
  return 0;
}
