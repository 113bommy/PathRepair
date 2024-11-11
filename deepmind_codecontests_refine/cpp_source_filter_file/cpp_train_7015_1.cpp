#include <bits/stdc++.h>
using namespace std;
const int MAX = 100011;
const int K = 48;
const int MOD = 95542721;
int n, a[MAX], st[MAX << 2][K], carry[MAX << 2];
inline int smod(int x, int mod) { return x >= mod ? x - mod : x; }
void build(int v, int l, int r) {
  if (l == r) {
    st[v][0] = a[l];
    for (int k = 1; k < K; ++k) {
      st[v][k] = (1LL * st[v][k - 1] * st[v][k - 1]) % MOD;
      st[v][k] = (1LL * st[v][k] * st[v][k - 1]) % MOD;
    }
  } else {
    int nl = v << 1, nr = nl | 1, mid = (l + r) >> 1;
    build(nl, l, mid);
    build(nr, mid + 1, r);
    for (int k = 0; k < K; ++k) st[v][k] = smod(st[nl][k] + st[nr][k], MOD);
  }
}
void push(int v, int nl, int nr) {
  if (carry[v]) {
    carry[nl] = smod(carry[nl] + carry[v], K);
    carry[nr] = smod(carry[nr] + carry[v], K);
    rotate(st[nl], st[nl] + carry[v], st[nl] + K);
    rotate(st[nr], st[nr] + carry[v], st[nr] + K);
    carry[v] = 0;
  }
}
int query(int v, int l, int r, int i, int j) {
  if (l > j || r < i) return 0;
  if (l >= i && r <= j)
    return st[v][0];
  else {
    int nl = v << 1, nr = nl | 1, mid = (l + r) >> 1;
    push(v, nl, nr);
    return smod(query(nl, l, mid, i, j) + query(nr, mid + 1, r, i, j), MOD);
  }
}
int query(int i, int j) { return query(1, 1, n, i, j); }
void cube(int v, int l, int r, int i, int j) {
  if (l > j || r < i) return;
  if (l >= i && r <= j) {
    rotate(st[v], st[v] + 1, st[v] + K);
    carry[v] = smod(carry[v] + 1, K);
  } else {
    int nl = v << 1, nr = nl | 1, mid = (l + r) >> 1;
    push(v, nl, nr);
    cube(nl, l, mid, i, j);
    cube(nr, mid + 1, r, i, j);
    for (int k = 0; k < K; ++k) st[v][k] = smod(st[nl][k] + st[nr][k], MOD);
  }
}
void cube(int i, int j) { cube(1, 1, n, i, j); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q-- > 0) {
    int t, l, r;
    scanf("%d%d%d", &t, &l, &r);
    if (t == 1)
      printf("%d\n", query(l, r));
    else
      cube(l, r);
  }
  return 0;
}
