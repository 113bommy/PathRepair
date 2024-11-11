#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, m, ans, k;
  for (cin >> t; t--;) {
    scanf("%lld%lld", &n, &m);
    k = (n - m) / (m + 1);
    ans = (((n + 1) * n) / 2) - (((k * (k + 1)) / 2) * (m + 1)) -
          ((((n - m) % (m + 1)) * (k + 1)));
    printf("%lld", ans);
  }
  return 0;
}
