#include <bits/stdc++.h>
using std::max;
using std::min;
int n, m, q;
int h[(300000 + 5)], tot;
struct Edge {
  int to, next;
} e[(300000 + 5) * 2];
int dfn[(300000 + 5)], low[(300000 + 5)], cnt;
int st[(300000 + 5)], tp;
int nxt[(300000 + 5)];
long long sum[(300000 + 5)];
void Read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}
void Write(long long x) {
  if (x >= 10) Write(x / 10);
  putchar(x % 10 + '0');
}
void AddEdge(int u, int v) {
  e[++tot].to = v;
  e[tot].next = h[u];
  h[u] = tot;
}
void Tarjan(int u) {
  dfn[u] = low[u] = ++cnt;
  st[++tp] = u;
  int v;
  for (int i = h[u]; i; i = e[i].next) {
    v = e[i].to;
    if (!dfn[v]) {
      Tarjan(v);
      low[u] = min(low[u], low[v]);
      if (dfn[u] <= low[v]) {
        int mn = u, mx = u, tmp = 1;
        while (st[tp] != u) {
          ++tmp;
          mn = min(mn, st[tp]);
          mx = max(mx, st[tp]);
          --tp;
        }
        if (tmp >= 3) nxt[mn] = min(nxt[mn], mx);
      }
    } else
      low[u] = min(low[u], dfn[v]);
  }
}
int main() {
  Read(n), Read(m);
  int u, v;
  for (int i = 1; i <= m; ++i) Read(u), Read(v), AddEdge(u, v), AddEdge(v, u);
  for (int i = 1; i <= n; ++i) nxt[i] = n + 1;
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) Tarjan(i);
  for (int i = n - 1; i; --i) nxt[i] = min(nxt[i + 1], nxt[i]);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + nxt[i] - i;
  Read(q);
  int ql, qr, l, r, mid;
  long long ans;
  while (q--) {
    Read(ql), Read(qr);
    l = ql - 1, r = qr;
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (nxt[mid] > qr)
        r = mid - 1;
      else
        l = mid;
    }
    ans = sum[r] - sum[ql - 1] + (long long)(qr - r + 1) * (qr - r) / 2;
    Write(ans), putchar('\n');
  }
  return 0;
}
