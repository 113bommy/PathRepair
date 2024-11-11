#include <bits/stdc++.h>
using namespace std;
const int INF = 1e7 + 10;
const int N = 7;
int n;
int l[N], r[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", l + i, r + i);
  }
  double ans = 0;
  for (int msk = 1; msk < (1 << n); ++msk) {
    if (__builtin_popcount(msk) > 1) {
      int ll = 0, rr = INF;
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          ll = max(ll, l[i]);
          rr = min(rr, r[i]);
        }
      }
      for (int k = ll; k <= rr; ++k) {
        long long cnt = 1;
        for (int i = 0; i < n; ++i) {
          if (!(msk & (1 << i))) {
            cnt *= max(0, min(k - 1, r[i]) - l[i] + 1);
          }
        }
        ans += cnt * k;
      }
      continue;
    }
    for (int msk2 = 0; msk2 < (1 << n); ++msk2) {
      if (msk != (1 << n) - 1 && !msk2) continue;
      if (msk2 & msk) continue;
      int ll1 = 0, rr1 = INF;
      int ll2 = 0, rr2 = INF;
      for (int i = 0; i < n; ++i) {
        if (msk & (1 << i)) {
          ll1 = max(ll1, l[i]);
          rr1 = min(rr1, r[i]);
        }
        if (msk2 & (1 << i)) {
          ll2 = max(ll2, l[i]);
          rr2 = min(rr2, r[i]);
        }
      }
      for (int k = ll2; k <= rr2; ++k) {
        long long cnt = 1;
        for (int i = 0; i < n; ++i) {
          if (msk & (1 << i)) continue;
          if (msk2 & (1 << i)) continue;
          cnt *= max(0, min(k - 1, r[i]) - l[i] + 1);
        }
        cnt *= max(0, rr1 - max(ll1, k + 1) + 1);
        ans += cnt * k;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    ans /= (r[i] - l[i] + 1);
  }
  printf("%.12f\n", ans);
  return 0;
}
