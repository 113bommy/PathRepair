#include <bits/stdc++.h>
int main() {
  int n, k, r(-1), s(100000000), t;
  int a[100000];
  std::scanf("%d%d", &n, &k);
  for (int i(0); i < n; ++i) std::scanf("%d", a + i);
  for (int i(0); i < k; ++i) {
    t = 0;
    for (int j(0); j < n / k; ++j) t += a[i + j * k];
    if (t < s) r = i, s = t;
  }
  std::printf("%d\n", r + 1);
  return 0;
}
