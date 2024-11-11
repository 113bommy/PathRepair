#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
const int INF = 1e9;
struct STree {
  vector<int> st;
  int n;
  STree(int n = 0) : st(4 * n + 5, -INF), n(n) {}
  void init(int k, int s, int e, int *a) {
    if (s + 1 == e) {
      st[k] = a[s];
      return;
    }
    int m = (s + e) / 2;
    init(2 * k, s, m, a);
    init(2 * k + 1, m, e, a);
    st[k] = max(st[2 * k], st[2 * k + 1]);
  }
  void upd(int k, int s, int e, int p, int v) {
    if (s + 1 == e) {
      st[k] = v;
      return;
    }
    int m = (s + e) / 2;
    if (p < m)
      upd(2 * k, s, m, p, v);
    else
      upd(2 * k + 1, m, e, p, v);
    st[k] = max(st[2 * k], st[2 * k + 1]);
  }
  int query(int k, int s, int e, int a, int b) {
    if (s >= b || e <= a) return -INF;
    if (s >= a && e <= b) return st[k];
    int m = (s + e) / 2;
    return max(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
  }
  void init(int *a) { init(1, 0, n, a); }
  void upd(int p, int v) { upd(1, 0, n, p, v); }
  int query(int a, int b) { return query(1, 0, n, a, b); }
} R[40];
int n, k, A[MAXN][40];
int val(vector<int> &V, int bm) {
  int ans = 0;
  for (int i = (0); i < (int)(k); i++) {
    ans = ans + V[i] * ((bm & (1 << i)) ? -1 : 1);
  }
  return ans;
}
int main() {
  while (scanf("%d %d", &n, &k) >= 1) {
    for (int i = (0); i < (int)((1 << k)); i++) R[i] = STree(n);
    for (int i = (0); i < (int)(n); i++) {
      vector<int> V(k);
      for (int j = (0); j < (int)(k); j++) scanf("%d", &V[j]);
      for (int j = (0); j < (int)((1 << k)); j++) A[j][i] = val(V, j);
    }
    for (int i = (0); i < (int)((1 << k)); i++) R[i].init(A[i]);
    int q;
    scanf("%d", &q);
    for (int cs = (0); cs < (int)(q); cs++) {
      int tp;
      scanf("%d", &tp);
      if (tp == 1) {
        int id;
        vector<int> V(k);
        scanf("%d", &id);
        for (int j = (0); j < (int)(k); j++) scanf("%d", &V[j]);
        id--;
        for (int j = (0); j < (int)((1 << k)); j++) R[j].upd(id, val(V, j));
      } else {
        int ans = 0, l, r;
        scanf("%d %d", &l, &r);
        l--;
        for (int i = (0); i < (int)((1 << k)); i++) {
          int a = R[i].query(l, r);
          int b = R[(1 << k) - 1 - i].query(l, r);
          ans = max(ans, a + b);
        }
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
