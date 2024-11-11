#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  int max_val = 0;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i], max_val = max(max_val, a[i]);
  auto ck = [&](long long mid) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
      if (!a[i]) continue;
      long long x = mid - 1;
      long long y = x + n - 1 - i;
      x = min(y - x, x);
      double temp = a[i];
      for (long long j = 1; j <= x; ++j) {
        temp *= (y - x + j) / j;
        if (temp >= k) return 1;
      }
      sum += temp;
      if (sum >= k) return 1;
    }
    return 0;
  };
  auto bf = [&]() {
    if (max_val >= k) {
      cout << 0 << '\n';
      return;
    }
    long long l = 1, r = k;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (ck(mid))
        r = mid - 1;
      else
        l = mid + 1;
    }
    cout << l << '\n';
  };
  bf();
  return 0;
}
