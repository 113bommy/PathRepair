#include <bits/stdc++.h>
std::pair<int, int> mp[200000];
int main() {
  short t;
  scanf("%hd", &t);
  while (t-- > 0) {
    int n;
    long long a = 0, b = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &mp[i].first);
    for (int i = 0; i < n; i++) {
      scanf("%d", &mp[i].second);
      a += mp[i].second;
    }
    std::sort(mp, mp + n);
    for (int i = 0; i < n; i++) {
      long long _a = a - mp[i].second, _b = std::max(b, (long long)mp[i].first);
      if (std::max(a, b) > std::max(_a, _b)) {
        a = _a;
        b = _b;
      }
    }
    printf("%lld\n", std::max(a, b));
  }
  return 0;
}
