#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    std::set<int> all;
    int n;
    std::cin >> n;
    while (n--) {
      int tmp;
      std::cin >> tmp;
      while ((tmp & 1) == 0) {
        all.insert(tmp);
        tmp >>= 1;
      }
    }
    printf("%lld\n", all.size());
  }
  return 0;
}
