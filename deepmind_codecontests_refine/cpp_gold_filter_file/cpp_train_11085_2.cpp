#include <bits/stdc++.h>
int main() {
  int n, a, r;
  int c[3] = {};
  std::scanf("%d", &n);
  while (0 < n--) {
    std::scanf("%d", &a);
    c[a - 1]++;
  }
  r = std::min({c[0] + c[1], c[0] + c[2], c[1] + c[2]});
  std::printf("%d\n", r);
  return 0;
}
