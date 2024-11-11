#include <bits/stdc++.h>
using namespace std;
int n, m, t, tmp;
long long ans, la;
int main() {
  scanf("%d%d", &n, &m);
  if (m + m >= n) {
    puts("0");
    return 0;
  }
  for (int k, i = m + 1; i < min(n - m, (n + 1) / 2 + 1); ++i) {
    k = n - m;
    tmp = (i + i - m) * (n + 1 - i);
    t = n + 1 - i;
    la = ans;
    for (int j = m + 1; j < n - m && k > m; ++j) {
      tmp -= t;
      for (; k > m && k * (i + j) >= tmp; --k)
        ;
      ans += k - m;
    }
  }
  printf("%I64d\n", ans * 6LL - (n & 1) * (ans - la) * 3LL);
  return 0;
}
