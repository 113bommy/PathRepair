#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};
long long a, b, q, l, t, m;
int main() {
  scanf("%lld%lld%lld", &a, &b, &q);
  while (q--) {
    scanf("%lld%lld%lld", &l, &t, &m);
    l--;
    long long s = l, e = 1e9;
    bool B = 0;
    while (s < e) {
      long long mid = (s + e + 1) / 2;
      long long z = (mid * (mid - 1)) / 2 - ((l) * (l - 1)) / 2;
      z = z * b + a * (mid - l + 1);
      if (z <= m * t && a + (mid - 1) * b <= t)
        s = mid;
      else
        e = mid - 1;
    }
    printf("%lld\n", (s == l ? -1 : s));
  }
  return 0;
}
