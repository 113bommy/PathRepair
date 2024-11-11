#include <bits/stdc++.h>
long long a[200001], sum = 0;
int n, m;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    sum += a[i];
  }
  std::sort(a + 1, a + n + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    int l = 1, r = n + 1, pos = n + 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (a[mid] >= u) {
        r = mid;
        pos = std::min(pos, mid);
      } else {
        l = mid + 1;
      }
    }
    long long ans = 0;
    if (pos != n + 1) {
      if (sum - a[pos] >= v)
        ans = 0;
      else
        ans = v - (sum - a[pos]);
      if (pos > 1) {
        if (sum - a[pos - 1] >= v)
          ans = std::min(ans, u - a[pos - 1]);
        else
          ans = std::min(ans, u - a[pos - 1] + v - (sum - a[pos - 1]));
      }
    } else {
      pos = n;
      ans = u - a[pos];
      if (v > sum - a[pos]) ans += v - (sum - a[pos]);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
