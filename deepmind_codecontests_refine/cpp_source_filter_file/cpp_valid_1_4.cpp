#include <bits/stdc++.h>
using namespace std;
const long long N = 6e3 + 5;
long long n, ans1, ans2, x[N], y[N], cnt[4][4];
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; ++i)
    cin >> x[i] >> y[i], ++cnt[x[i] % 4][y[i] % 4];
  for (long long i = 1; i <= n; ++i)
    for (long long j = i + 1; j <= n; ++j) {
      if (abs(x[i] - x[j]) % 4 != 0 || abs(y[i] - y[j]) % 4 != 0) continue;
      long long needx = (x[i] % 4 == 0 ? 2 : 0),
                needy = (y[i] % 4 == 0 ? 2 : 0);
      for (long long k = 0; k <= 3; ++k)
        ans1 += cnt[k][needy], ans1 += cnt[needx][k];
      ans1 -= cnt[needx][needy];
      needx = (!needx ? 2 : 0), needy = (!needy ? 2 : 0);
      ans2 += cnt[needx][needy];
    }
  printf("%lld", ans1 + ans2 / 3);
  return 0;
}
