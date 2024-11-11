#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, t, x, y, p, q, i, j, k, e1, e2;
  cin >> t;
  while (t--) {
    cin >> x >> y >> p >> q;
    if (x * q == p * y) {
      printf("0\n");
      continue;
    }
    if (p == q || !p) {
      printf("-1\n");
      continue;
    }
    a = ceil((y - x + 0.0) / (q - p));
    e1 = p * a, e2 = q * a;
    if (e1 < x) e1 = p * ceil((0.0 + x) / p), e2 = q * ceil((x + 0.0) / p);
    printf("%I64d\n", e2 - y);
  }
  return 0;
}
