#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long a[maxn], k, st, en;
long long ans[maxn], s[maxn], one;
int cmp(const long long &x, const long long &y) { return x > y; }
int main(void) {
  int n, q, i, j;
  while (scanf("%d", &n) != EOF) {
    for (i = 1; i <= n; i++) {
      scanf("%I64d", &a[i]);
    }
    sort(a + 1, a + 1 + n, cmp);
    one = s[0] = 0ll;
    long long cnt = 0ll;
    for (i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i];
      one += a[i] * cnt++;
    }
    scanf("%d", &q);
    for (i = 1; i <= q; i++) {
      scanf("%I64d", &k);
      if (k == 1) {
        ans[i] = one;
        continue;
      }
      st = 1ll;
      int lu = 0;
      long long p = 1ll;
      long long sum = 0ll;
      while (st <= (long long)n) {
        en = st + p - 1;
        if (en > n) en = n;
        sum += (s[en] - s[st - 1]) * lu;
        st = en + 1;
        lu++;
        p *= k;
      }
      ans[i] = sum;
    }
    for (i = 1; i <= q; i++) printf("%I64d ", ans[i]);
    putchar('\n');
  }
  return 0;
}
