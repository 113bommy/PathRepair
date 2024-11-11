#include <bits/stdc++.h>
using namespace std;
long long n, k, d[200005], p[12][200005];
long long cnt[12];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &d[i]);
    long long t = d[i] * 10;
    for (int j = 1; j <= 10; j++) {
      p[j][cnt[j]++] = t % k;
      t *= 10;
      t %= k;
    }
  }
  for (int i = 1; i <= 10; i++) sort(p[i], p[i] + cnt[i]);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int lt = 0;
    long long t = d[i];
    while (t) {
      t /= 10;
      lt++;
    }
    long long z = k - d[i] % k;
    z %= k;
    if (binary_search(p[lt], p[lt] + cnt[lt], z)) {
      int r = upper_bound(p[lt], p[lt] + cnt[lt], z) - p[lt];
      int l = lower_bound(p[lt], p[lt] + cnt[lt], z) - p[lt];
      ans += r - l;
    }
    t = d[i];
    while (lt--) {
      t *= 10;
      t % k;
    }
    if ((t + d[i]) % k == 0) ans--;
  }
  cout << ans;
  return 0;
}
