#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, E = 8000000;
int n;
int acc[N * 2], fa[N * 2], L[N * 2], R[N * 2];
long long v[E], size[E], tot, ans, sum[E];
int lc[E], rc[E], root[N * 2];
int gf(int x) { return fa[x] == 0 ? x : fa[x] = gf(fa[x]); }
void remove(int x) { ans = (ans - v[root[x]] - (L[x] - 1) * sum[root[x]]); }
void add(int x) { ans = (ans + v[root[x]] + (L[x] - 1) * sum[root[x]]); }
void update(int x) {
  sum[x] = (sum[lc[x]] + sum[rc[x]]);
  size[x] = size[lc[x]] + size[rc[x]];
  v[x] = v[rc[x]] + v[lc[x]] + size[rc[x]] * sum[lc[x]];
}
int tg;
void modify(int &x, int l, int r) {
  if (x == 0) x = ++tot;
  if (l == r) {
    size[x]++;
    v[x] = sum[x] = (sum[x] + l);
    return;
  }
  if (tg <= (l + r >> 1))
    modify(lc[x], l, l + r >> 1);
  else
    modify(rc[x], (l + r >> 1) + 1, r);
  update(x);
}
void mergeT(int &aa, int bb) {
  if (aa == 0) {
    aa = bb;
    return;
  }
  if (bb == 0) return;
  mergeT(lc[aa], lc[bb]);
  mergeT(rc[aa], rc[bb]);
  update(aa);
}
void merge(int a, int b) {
  if (a == b) return;
  fa[a] = b;
  remove(a), remove(b);
  mergeT(root[b], root[a]);
  L[b] = ((L[a]) < (L[b]) ? (L[a]) : (L[b]));
  R[b] = ((R[a]) > (R[b]) ? (R[a]) : (R[b]));
  add(b);
}
int main() {
  cin >> n;
  for (int i = 1; i < N * 2; i++) L[i] = R[i] = i;
  for (int i = 1; i <= n; i++) {
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    ans = (ans - a * b);
    int f = gf(a);
    if (i == 9) {
      int kkk = i;
    }
    if (acc[a] == 1) {
      remove(f);
      tg = b, modify(root[f], 1, n);
      add(f);
      merge(f, gf(++R[f]));
      printf("%I64d\n", ans);
      continue;
    } else {
      remove(f);
      acc[a] = 1;
      L[f] = ((L[f]) < (a) ? (L[f]) : (a));
      R[f] = ((R[f]) > (a) ? (R[f]) : (a));
    }
    tg = b, modify(root[f], 1, n);
    add(f);
    merge(f, gf(R[f] + 1));
    if (acc[L[f] - 1]) merge(gf(f), gf(L[f] - 1));
    printf("%I64d\n", ans);
  }
}
