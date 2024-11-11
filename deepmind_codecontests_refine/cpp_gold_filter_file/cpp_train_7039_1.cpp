#include <bits/stdc++.h>
using namespace std;
int main() {
  long long nines[15];
  nines[0] = 0;
  for (int i = 0; i < (int)(14); i++) nines[i + 1] = nines[i] * 10 + 9;
  long long l, r;
  while (scanf("%I64d%I64d", &l, &r) != EOF) {
    long long ans = 0;
    for (int i = 1; i < 15; i++) {
      if ((nines[i - 1] < l && l <= nines[i]) ||
          (nines[i - 1] < r && r <= nines[i])) {
        long long x = nines[i] / 2;
        if ((l <= x && x <= r) || (l <= x + 1 && x + 1 <= r))
          ans = max(ans, x * (nines[i] - x));
        else {
          ans = max(ans, l * (nines[i] - l));
          if (nines[i - 1] < r && r <= nines[i])
            ans = max(ans, r * (nines[i] - r));
        }
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
