#include <bits/stdc++.h>
int main() {
  int n;
  long v;
  std::scanf("%d", &n);
  v = (long long)(n - 1) * n / 2;
  if (v * 2 % n != v % n) {
    std::puts("-1");
    return 0;
  }
  for (int i(0); i < 2; ++i) {
    for (int j(0); j < n; ++j) {
      if (0 < j) std::printf(" ");
      std::printf("%d", j);
    }
    std::puts("");
  }
  for (int i(0); i < n; ++i) {
    if (0 < i) std::printf(" ");
    std::printf("%d", i * 2 % n);
  }
  std::puts("");
  return 0;
}
