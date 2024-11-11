#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10010;
;
struct qu {
  int l, r, x;
  qu() {}
  qu(int L, int R, int X) {
    l = L;
    r = R;
    x = X;
  }
};
vector<qu> qs[MAXN];
int lf[MAXN], rg[MAXN];
int get_cnt(int x) {
  for (int i = 0;; i++) {
    if ((1 << i) > x) {
      return i;
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    int t, level, l, r, x, p;
    cin >> t;
    if (t == 1) {
      cin >> level >> l >> r >> x;
      qs[level].push_back(qu(l, r, x));
    } else {
      cin >> level >> p;
      set<int> sol;
      lf[level] = p;
      rg[level] = p;
      while (level <= n) {
        for (int i = 0; i < (int)(qs[level].size()); i++) {
          if (qs[level][i].l > rg[level] || qs[level][i].r < lf[level]) {
            continue;
          }
          sol.insert(qs[level][i].x);
        }
        if (level < n) {
          lf[level + 1] = lf[level] - 1 + get_cnt(lf[level] - 1) + 1;
          rg[level + 1] = rg[level] + get_cnt(rg[level]);
        }
        level++;
      }
      cout << sol.size() << '\n';
    }
  }
}
