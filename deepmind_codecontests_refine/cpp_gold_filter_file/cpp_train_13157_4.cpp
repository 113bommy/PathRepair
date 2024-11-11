#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m;
long long an;
int main() {
  scanf("%d%d", &n, &m);
  for (i = m + 1; i + i - 1 <= n; i++) {
    long long s = 0;
    k = n - m;
    for (j = m + 1; j + m <= n; j++) {
      for (; k > m;) {
        int s = (n + 1 - i) * (j - 2 * i) + j * k + i * k;
        if (s >= 0)
          k--;
        else
          break;
      }
      if (k == m) break;
      s += k - m;
    }
    an += s;
    if (i + i <= n) an += s;
  }
  printf("%I64d\n", an * 3);
  return 0;
}
