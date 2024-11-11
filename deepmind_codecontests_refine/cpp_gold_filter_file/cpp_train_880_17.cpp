#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
template <typename T1, typename T2>
inline void remin(T1& a, T2 b) {
  a = min(a, (T1)b);
}
const int maxN = 1 << 18, maxTS = maxN * 2;
template <typename Tp>
struct Tree_t {
  int offset, qbegin, qend;
  Tp T[maxTS], res, x;
  void qpriv(int v, int left, int right) {
    if (left >= qend or right <= qbegin) return;
    if (left >= qbegin and right <= qend) {
      remin(res, T[v]);
      return;
    }
    qpriv(v * 2, left, (left + right) / 2);
    qpriv(v * 2 + 1, (left + right) / 2, right);
  }
  void init(int n) {
    for (offset = 1; offset < n; offset *= 2)
      ;
    fill(T, T + offset * 2, 0);
  }
  void updt(int v, int x) {
    v += offset;
    T[v] = x;
    for (v /= 2; v != 0; v /= 2) T[v] = min(T[v * 2], T[v * 2 + 1]);
  }
  Tp query(int a, int b) {
    qbegin = a + offset;
    qend = b + offset + 1;
    res = maxN;
    qpriv(1, offset, offset * 2);
    return res;
  }
};
Tree_t<long long> tree;
vector<int> ph[maxN], pv[maxN];
vector<vector<int> > qh[maxN], qv[maxN];
bool res[maxN];
void swep(int n, int m, vector<int>* P, vector<vector<int> >* Q) {
  tree.init(m + 1);
  for (int i = (1); i < (n + 1); i++) {
    for (int v : P[i]) tree.updt(v, i);
    for (auto vec : Q[i]) {
      int a = vec[0];
      int b = vec[1];
      int bord = vec[2];
      int ind = vec[3];
      if (tree.query(a, b) >= bord) res[ind] = true;
    }
  }
}
void solve() {
  int w, h, q, k;
  scanf("%d%d%d%d", &w, &h, &k, &q);
  while (k--) {
    int c, r;
    scanf("%d%d", &c, &r);
    ph[c].push_back(r);
    pv[r].push_back(c);
  }
  for (int i = (0); i < (q); i++) {
    int col1, row1, col2, row2;
    scanf("%d%d%d%d", &col1, &row1, &col2, &row2);
    qh[col2].push_back({row1, row2, col1, i});
    qv[row2].push_back({col1, col2, row1, i});
  }
  swep(w, h, ph, qh);
  swep(h, w, pv, qv);
  for (int i = (0); i < (q); i++) printf("%s\n", res[i] ? "YES" : "NO");
}
int main() {
  int t = 1;
  for (int tid = (1); tid < (t + 1); tid++) {
    solve();
  }
  return 0;
}
