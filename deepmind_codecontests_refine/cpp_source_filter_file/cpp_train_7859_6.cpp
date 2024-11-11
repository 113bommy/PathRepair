#include <bits/stdc++.h>
using namespace std;
const int maxn = 30000 + 10;
const int maxm = 800000 + 10;
const int P = 1e7 + 19;
const int Q = 1e9 + 7;
struct Edge {
  int next, v;
  Edge() {}
  Edge(int next, int v) : next(next), v(v) {}
} e[maxm];
struct Exhibit {
  int l, r, v, w;
  Exhibit() { l = r = 0; }
} a[maxn];
int n, m, q, K;
int head[maxm], cnt;
int query[maxn], dp[25][maxn];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline void AddEdge(int u, int v) {
  e[++cnt] = Edge(head[u], v);
  head[u] = cnt;
}
void Insert(int o, int l, int r, int ql, int qr, int p) {
  if (ql <= l && r <= qr) {
    AddEdge(o, p);
    return;
  }
  int mid = (l + r) >> 1, lson = o << 1, rson = lson | 1;
  if (qr <= mid)
    Insert(lson, l, mid, ql, qr, p);
  else if (ql > mid)
    Insert(rson, mid + 1, r, ql, qr, p);
  else {
    Insert(lson, l, mid, ql, qr, p);
    Insert(rson, mid + 1, r, ql, qr, p);
  }
}
void solve(int o, int l, int r, int dep) {
  for (int i = 0; i <= K; i++) dp[dep][i] = dp[dep - 1][i];
  for (int i = head[o], val, w; i; i = e[i].next) {
    int v = e[i].v;
    val = a[v].v, w = a[v].w;
    for (int k = K - w; k = 0; k--)
      dp[dep][k + w] = max(dp[dep][k + w], dp[dep][k] + val);
  }
  if (l == r) {
    int res = 0;
    for (int i = K; i >= 1; i--) {
      res = (long long)res * P % Q;
      res = ((long long)res + dp[dep][i]) % Q;
    }
    printf("%d\n", res);
    return;
  }
  int mid = (l + r) >> 1, lson = o << 1, rson = lson | 1;
  solve(lson, l, mid, dep + 1);
  solve(rson, mid + 1, r, dep + 1);
}
int main() {
  if (fopen("in.in", "r") != NULL) {
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
  }
  n = read(), K = read();
  for (int i = 1; i <= n; i++) a[i].v = read(), a[i].w = read();
  m = read();
  for (int i = 1, op; i <= m; i++) {
    op = read();
    if (op == 1) {
      n++;
      a[n].v = read(), a[n].w = read();
      a[n].l = i;
    } else if (op == 2) {
      op = read();
      a[op].r = i;
    } else
      query[++q] = i;
  }
  for (int i = 1, l, r; i <= n; i++) {
    if (!a[i].r) a[i].r = m + 1;
    l = lower_bound(query + 1, query + q + 1, a[i].l) - query;
    r = lower_bound(query + 1, query + q + 1, a[i].r) - query - 1;
    if (l <= r) Insert(1, 1, q, l, r, i);
  }
  solve(1, 1, q, 1);
  return 0;
}
