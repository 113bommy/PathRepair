#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  long long n, k, a[210101], ans = 0;
  std::cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
    if (a[i] <= k && a[i - 1] != 0)
      ans++, a[i] = 0;
    else
      ans += a[i] / k, a[i] %= k;
  }
  if (a[n] != 0) ans++;
  std::cout << ans << "\n";
  return 0;
}
