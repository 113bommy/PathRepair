#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, len, d = 0, val = 0;
  long long cur = 1, ans = 0,
            p[11] = {1,         10,         100,        1000,
                     10000,     100000,     1000000,    10000000,
                     100000000, 1000000000, 10000000000};
  char k[61];
  scanf("%lld%s", &n, k);
  len = strlen(k);
  for (int i = len - 1; i >= 0; i--) {
    if (k[i] == '0') {
      int cnt = 1;
      bool ok = 0;
      while (!ok && p[d + cnt] < n) {
        if (i - cnt >= 0 && (k[i - cnt] != '0') &&
            (val + p[d + cnt] * (k[i - cnt] - '0')))
          val += p[d + cnt] * (k[i - cnt] - '0'), ok = 1, i -= (cnt),
                                                  d += cnt + 1;
        cnt++;
      }
      if (!ok) {
        ans += cur * val;
        cur *= n;
        d = d ? 1 : 0;
        val = 0;
      }
    } else if (p[d] * (k[i] - '0') + val < n)
      val += p[d] * (k[i] - '0'), d++;
    else {
      ans += cur * val;
      cur *= n;
      d = 1;
      val = k[i] - '0';
    }
  }
  ans += cur * val;
  printf("%lld", ans);
}
