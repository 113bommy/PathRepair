#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
struct DJS {
  int cc, p[42];
  void init(int n, int _cc) {
    cc = _cc;
    for (int i = 0; i < n; i++) p[i] = i;
  }
  int f(int x) { return x == p[x] ? x : p[x] = f(p[x]); }
  void uni(int x, int y) {
    if (f(x) == f(y)) return;
    p[f(x)] = f(y);
    cc--;
  }
};
int n, m, q, a[11][101010];
int who[44];
inline DJS merge(const DJS& lhs, const DJS& rhs, int pos) {
  DJS djs;
  djs.init(n * 4, 0);
  djs.cc = lhs.cc + rhs.cc;
  for (int i = 0; i < n + n; i++) {
    djs.p[i] = lhs.p[i];
    djs.p[n + n + i] = n + n + rhs.p[i];
  }
  for (int i = 0; i < n; i++)
    if (a[i][pos] == a[i][pos + 1]) djs.uni(i + n, i + n + n);
  DJS ret;
  ret.init(n + n, djs.cc);
  for (int i = 0; i < n * 4; i++) who[i] = 0;
  for (int i = 0; i < n; i++) {
    if (who[djs.f(i)] == 0) who[djs.f(i)] = i;
    ret.p[i] = who[djs.f(i)];
  }
  for (int i = 0; i < n; i++) {
    if (who[djs.f(3 * n + i)] == 0) who[djs.f(3 * n + i)] = n + i;
    ret.p[n + i] = who[djs.f(3 * n + i)];
  }
  return ret;
}
struct SegT {
  DJS djs[101010 << 2];
  void build_st(int no, int l, int r) {
    if (l == r) {
      djs[no].init(n + n, n + n);
      for (int i = 0; i < n; i++) djs[no].uni(i, i + n);
      for (int i = 1; i < n; i++)
        if (a[i][l] == a[i - 1][l]) djs[no].uni(i - 1, i);
      return;
    }
    build_st((no << 1), l, ((l + r) >> 1));
    build_st((1 + (no << 1)), ((l + r) >> 1) + 1, r);
    djs[no] = merge(djs[(no << 1)], djs[(1 + (no << 1))], ((l + r) >> 1));
  }
  DJS query(int no, int l, int r, int ql, int qr) {
    if (l == ql and r == qr) return djs[no];
    if (qr <= ((l + r) >> 1))
      return query((no << 1), l, ((l + r) >> 1), ql, qr);
    if (((l + r) >> 1) < ql)
      return query((1 + (no << 1)), ((l + r) >> 1) + 1, r, ql, qr);
    return merge(
        query((no << 1), l, ((l + r) >> 1), ql, ((l + r) >> 1)),
        query((1 + (no << 1)), ((l + r) >> 1) + 1, r, ((l + r) >> 1) + 1, qr),
        ((l + r) >> 1));
  }
} st;
void init() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
}
void solve() {
  st.build_st(1, 1, m);
  while (q--) {
    int li, ri;
    scanf("%d%d", &li, &ri);
    printf("%d\n", st.query(1, 1, m, li, ri).cc);
  }
}
int main() {
  init();
  solve();
}
