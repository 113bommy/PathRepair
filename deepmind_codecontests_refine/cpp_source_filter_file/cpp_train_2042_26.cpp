#include <bits/stdc++.h>
using namespace std;
const int NN = (int)1e6;
int n, a[1000010], cnt[NN + 10], f, x, y;
long long sum[NN + 10], ans = (long long)1e18;
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    sum[a[i]] += a[i];
  }
  for (int i = 1; i <= NN; i++) {
    cnt[i] += cnt[i - 1];
    sum[i] += sum[i - 1];
  }
  for (int g = 2; g <= NN; g++) {
    long long tem = 0;
    f = max(1, g - x / y);
    f = min(f, g);
    for (int j = g; j <= NN; j += g) {
      if (j - g <= j - g + f - 1)
        tem += 1ll * (cnt[j - g + f - 1] - cnt[j - g]) * x;
      if (j - g + f - 1 <= j - 1)
        tem += 1ll *
               (j * (cnt[j - 1] - cnt[j - g + f - 1]) - sum[j - 1] +
                sum[j - g + f - 1]) *
               y;
    }
    ans = min(ans, tem);
  }
  cout << ans << endl;
  return 0;
}
