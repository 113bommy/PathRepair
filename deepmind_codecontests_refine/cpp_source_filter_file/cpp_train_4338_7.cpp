#include <bits/stdc++.h>
using namespace std;
int f(int a, int b) { return abs(a - b); }
int main() {
  std::ios_base::sync_with_stdio(false);
  ;
  int n, m, cl, ce, v;
  cin >> n >> m >> cl >> ce >> v;
  int L[cl + 1], E[ce + 1];
  for (int i = 0; i < cl; i++) cin >> L[i];
  for (int i = 0; i < ce; i++) cin >> E[i];
  sort(L, L + cl);
  sort(E, E + ce);
  int q;
  cin >> q;
  int x1, x2, y1, y2;
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y1 - y2) << "\n";
      continue;
    }
    int X1 = INT_MAX, X2 = INT_MAX, X3 = INT_MAX, X4 = INT_MAX;
    if (cl != 0) {
      int k = upper_bound(L, L + cl, y1) - L;
      int kk = k - 1;
      if (k < cl) X1 = f(x1, x2) + f(y1, L[k]) + f(y2, L[k]);
      if (kk >= 0) X2 = f(x1, x2) + f(y1, L[kk]) + f(y2, L[kk]);
    }
    if (ce != 0) {
      int k = upper_bound(E, E + ce, y1) - E;
      int kk = k - 1;
      if (k < cl) X3 = f(y1, E[k]) + f(y2, E[k]) + (f(x1, x2) + v - 1) / v;
      if (kk >= 0) X4 = f(y1, E[kk]) + f(y2, E[kk]) + (f(x1, x2) + v - 1) / v;
    }
    cout << min(min(X1, X2), min(X3, X4)) << "\n";
  }
  return 0;
}
