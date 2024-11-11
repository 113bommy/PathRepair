#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 300005;
vector<pair<int, int> > ask[N];
int a[N];
int n, q, k;
int val[N];
void calc() {
  static int q[N], ql, qr;
  ql = 1, qr = 0;
  for (int i = 1; i <= n; i++) {
    while (ql <= qr && a[q[qr]] > a[i]) --qr;
    while (ql <= qr && i - q[ql] > k) ++ql;
    q[++qr] = i;
    val[i] = a[q[ql]];
  }
}
long long ans[N];
int pos[N], len;
long long sum[N << 2];
int cov[N << 2];
void pushup(int u) { sum[u] = sum[(u << 1)] + sum[(u << 1 | 1)]; }
void pushcov(int u, int l, int r, int num) {
  cov[u] = num;
  sum[u] = 1ll * (r - l + 1) * num;
}
void pushdown(int u, int l, int r) {
  if (cov[u] != -1) {
    int mid = l + r >> 1;
    pushcov((u << 1), l, mid, cov[u]);
    pushcov((u << 1 | 1), mid + 1, r, cov[u]);
    cov[u] = -1;
  }
}
void build(int u, int l, int r) {
  cov[u] = -1;
  if (l == r) {
    sum[u] = a[pos[l]];
    return;
  }
  int mid = l + r >> 1;
  build((u << 1), l, mid);
  build((u << 1 | 1), mid + 1, r);
  pushup(u);
}
void update(int u, int l, int r, int ql, int qr, int num) {
  assert(ql <= qr);
  if (ql <= l && r <= qr) {
    pushcov(u, l, r, num);
    return;
  }
  pushdown(u, l, r);
  int mid = l + r >> 1;
  if (ql <= mid) update((u << 1), l, mid, ql, qr, num);
  if (qr > mid) update((u << 1 | 1), mid + 1, r, ql, qr, num);
  pushup(u);
}
long long query(int u, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[u];
  pushdown(u, l, r);
  int mid = l + r >> 1;
  long long res = 0;
  if (ql <= mid) res += query((u << 1), l, mid, ql, qr);
  if (qr > mid) res += query((u << 1 | 1), mid + 1, r, ql, qr);
  return res;
}
int main() {
  n = read(), q = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= q; i++) {
    int l = read(), r = read();
    ask[l].push_back({r, i});
  }
  calc();
  for (int re = 1; re <= k; re++) {
    static int stk[N], top;
    len = 0, top = 0;
    for (int i = re; i <= n; i += k) pos[++len] = i;
    build(1, 1, len);
    for (int i = len; i >= 1; i--) {
      int u = pos[i];
      for (auto [r, id] : ask[u]) {
        ans[id] = a[u] + query(1, 1, len, i + 1, (r - re) / k + 1);
      }
      while (top && val[pos[i]] < val[pos[stk[top]]]) --top;
      if (top)
        update(1, 1, len, i, stk[top] - 1, val[pos[i]]);
      else
        update(1, 1, len, i, len, val[pos[i]]);
      stk[++top] = i;
    }
  }
  for (int i = 1; i <= q; i++) print(ans[i], '\n');
  return 0;
}
