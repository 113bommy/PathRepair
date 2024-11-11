#include <bits/stdc++.h>
using namespace std;
int main() {
  long long c, w1, w2, h1, h2, ans = 0LL;
  scanf("%I64d %I64d %I64d %I64d %I64d", &c, &h1, &h2, &w1, &w2);
  if (w1 * w1 < c && (1.0 * h1 / w1 > 1.0 * h2 / w2 || w2 * w2 >= c))
    swap(h1, h2), swap(w1, w2);
  for (long long i = 0; i * i <= c && i * w1 <= c; ++i)
    ans = max(ans, h1 * i + ((c - w1 * i) / w2) * h2);
  printf("%I64d", ans);
  return 0;
}
