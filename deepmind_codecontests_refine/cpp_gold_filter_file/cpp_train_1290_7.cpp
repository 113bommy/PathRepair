#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, ans;
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  if (n >= k || m >= k) {
    printf("0\n");
    return 0;
  } else if (n <= 0 && m <= 0) {
    printf("-1\n");
    return 0;
  } else {
    ans = 0;
    if (n > m) swap(n, m);
    if (n < 0) {
      ans = (-n) / m;
      n += m * ans;
    }
    while (m < k) {
      x = n + m;
      n = m;
      m = x;
      if (n > m) swap(n, m);
      ans++;
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
