#include <bits/stdc++.h>
const int N = 3e5 + 233;
int n, m, A[N];
inline int check(int t) {
  for (int i = 1, last = 0; i <= n; ++i) {
    if (A[i] + t >= m) {
      int left = t - (m - A[i]);
      if (A[i] + left >= last) {
        continue;
      }
    }
    if (A[i] >= last) {
      last = A[i];
      continue;
    }
    if (A[i] + t >= last) {
      continue;
    }
    return 0;
  }
  return 1;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", A + i);
  int l = 0, r = m, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  std::cout << ans << std::endl;
  return 0;
}
