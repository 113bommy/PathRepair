#include <bits/stdc++.h>
using namespace std;
long long cnt[2000025], pre[2000025];
int main(void) {
  long long temp, x, y, c, ans;
  int n, i, t, d, st;
  scanf("%d%lld%lld", &n, &x, &y);
  for (i = 1; i <= n; i++) {
    scanf("%d", &t);
    cnt[t]++;
    pre[t] += t;
  }
  ans = x * n;
  c = x / y;
  for (i = 1; i <= 2000005; i++) {
    cnt[i] += cnt[i - 1];
    pre[i] += pre[i - 1];
  }
  for (d = 2; d <= 1000000; d++) {
    temp = 0;
    for (i = 0; i + d < 2000025; i += d) {
      if (i + d - c > i + 1) temp += (cnt[i + d - c - 1] - cnt[i]) * x;
      st = max(i + d - c, i + 1ll);
      temp += ((cnt[i + d - 1] - cnt[st - 1]) * (i + d) -
               (pre[i + d - 1] - pre[st - 1])) *
              y;
    }
    ans = min(ans, temp);
  }
  printf("%lld\n", ans);
  return 0;
}
