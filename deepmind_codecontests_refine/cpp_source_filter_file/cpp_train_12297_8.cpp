#include <bits/stdc++.h>
using namespace std;
long long l, r, n;
int main() {
  scanf("%I64d", &n);
  while (n--) {
    scanf("%I64d%I64d", &l, &r);
    long long m, odd, sum, p = r - l + 1, ans;
    sum = (r + l) * p / 2;
    if (r % 2 == 1) {
      if (l % 2 == 1) {
        m = (r - l) / 2 + 1;
        odd = (r + l) * m / 2;
      } else {
        m = (r - l - 1) / 2 + 1;
        odd = (r + l + 1) * m / 2;
      }
    } else {
      if (l % 2 == 1) {
        m = (r - l - 1) / 2 + 1;
        odd = (r + l) * m / 2;
      } else {
        m = (r - l - 2) / 2 + 1;
        odd = (r + l) * m / 2;
      }
    }
    ans = sum - 2 * odd;
    printf("%I64d\n", ans);
  }
}
