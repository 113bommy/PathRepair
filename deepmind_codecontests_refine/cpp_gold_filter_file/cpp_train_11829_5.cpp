#include <bits/stdc++.h>
const int maxn = 2e5 + 7;
const int maxm = 2e5 + 7;
struct Edge {
  int to;
  int last;
} a[maxm << 1];
struct Road {
  int x, y, z;
} c[maxm >> 1];
int n, m;
int ans;
int tot;
int d[maxn];
int head[maxn];
inline void HA(int x, int y) {
  a[++tot] = (Edge){y, head[x]};
  head[x] = tot;
  a[++tot] = (Edge){x, head[y]};
  head[y] = tot;
}
inline void Addans(int x, int y, int z) { c[++ans] = (Road){x, y, z}; }
inline int HAHA(int x, int prt) {
  d[x] = d[prt] + 1;
  int now = 0;
  for (int i = head[x]; i; i = a[i].last)
    if (a[i].to != prt && d[a[i].to] < d[x]) {
      int temp;
      if (d[a[i].to])
        temp = a[i].to;
      else
        temp = HAHA(a[i].to, x);
      if (temp) {
        if (now) Addans(now, x, temp);
        now = (now ? 0 : temp);
      }
    }
  if (now && prt) Addans(now, x, prt);
  return (now ? 0 : x);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, y; i <= m; ++i) scanf("%d%d", &x, &y), HA(x, y);
  for (int i = 1; i <= n; ++i)
    if (!d[i]) HAHA(i, 0);
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) printf("%d %d %d\n", c[i].x, c[i].y, c[i].z);
  return 0;
}
