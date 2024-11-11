#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e7;
long long p(long long n, long long k) {
  if (k == 0) return 1;
  if (k % 2 == 1)
    return min(INF, n * p(min(INF, n * n), k / 2));
  else
    return p(min(INF, n * n), k / 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    for (long long x = 1; p(x, k) <= a[i]; x++) {
      if ((a[i] % p(x, k)) == 0) a[i] /= p(x, k);
    }
  }
  long long ans = 0;
  map<long long, long long> K;
  for (long long i = 0; i < n; i++) {
    long long x = a[i];
    long long y = 1;
    for (long long p_ = 2; p_ <= 320; p_++) {
      long long alfa = 0;
      while (x % p_ == 0) {
        x /= p_;
        alfa++;
      }
      if (alfa > 0) y *= p(p_, k - alfa);
      y = min(y, INF);
    }
    if (x != 1) y *= p(x, k - 1);
    y = min(y, INF);
    ans += K[y];
    K[a[i]]++;
  }
  cout << ans << "\n";
}
