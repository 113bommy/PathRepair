#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<long long> v(n + 1), t(n + 1, 0), cumT(n + 1), ans(n + 1, 0),
      cntNeg(n + 2, 0);
  for (int i = 1; i <= n; ++i) scanf("%lld", &v[i]);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &t[i]), cumT[i] += cumT[i - 1] + t[i];
  for (int i = 1; i <= n; ++i) {
    int l = i, r = n, mark = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (cumT[mid] - cumT[i - 1] >= v[i]) {
        mark = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    if (mark != -1) {
      ans[mark] += v[i] - cumT[mark] + cumT[i - 1];
      cntNeg[mark + 1]++;
    }
  }
  for (int i = 1; i <= n; ++i) cntNeg[i] += cntNeg[i - 1];
  for (int i = 1; i <= n; ++i) {
    printf("%lld ", 1LL * t[i] * (i - cntNeg[i]) + ans[i]);
  }
  return 0;
}
