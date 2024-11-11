#include <bits/stdc++.h>
using namespace std;
inline void update(int &l, int &r, int nl, int nr) {
  if (nr - nl > r - l) l = nl, r = nr;
}
inline int intersec(int l1, int r1, int l2, int r2) {
  return max(0, min(r1, r2) - max(l1, l2));
}
int solve(int l1, int r1, int l2, int r2) {
  int ls[2][2] = {{l1, 1 << 30}, {l2, 1 << 30}},
      rs[2][2] = {{r1 + 1, 1 << 30}, {r2 + 1, 1 << 30}};
  int nls[2], nrs[2];
  int ans = 0;
  for (int k = 29; k >= 0; k--) {
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < 2; j++)
        ans = max(ans, intersec(ls[0][i], rs[0][i], ls[1][j], rs[1][j]));
    if (k) {
      for (int it = 0; it < 2; it++) {
        nls[0] = nrs[0] = 1;
        nls[1] = nrs[1] = (1 << k);
        for (int i = 0; i < 2; i++) {
          int lnow = ls[it][i], rnow = rs[it][i];
          if (lnow > (1 << k))
            lnow -= 1 << k, rnow -= 1 << k;
          else if ((1 << k) < rnow) {
            update(nls[0], nrs[0], 1, rnow - (1 << k));
            update(nls[1], nrs[1], lnow, 1 << k);
            continue;
          }
          update(nls[i], nls[i], lnow, rnow);
        }
        ls[it][0] = nls[0], ls[it][1] = nls[1];
        rs[it][0] = nrs[0], rs[it][1] = nrs[1];
      }
    }
  }
  return ans;
}
int main() {
  int l1, r1, l2, r2;
  while (scanf("%d%d%d%d", &l1, &r1, &l2, &r2) >= 1) {
    printf("%d\n", solve(l1, r1, l2, r2));
  }
  return 0;
}
