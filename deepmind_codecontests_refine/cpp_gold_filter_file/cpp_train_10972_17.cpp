#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
long long n, m, k;
inline long long POWER(long long base, long long p) {
  long long ret = 1, cur = base;
  while (p) {
    if (p & 1) ret = ret * cur % mod;
    p >>= 1;
    cur = cur * cur % mod;
  }
  return ret;
}
int main() {
  cin >> n >> m >> k;
  long long lo = 0, hi = n / k, ans = -1;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (m <= mid * k + (n / k - mid) * (k - 1) + n % k) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  cout << ((k * (POWER(2, ans + 1) - 2) % mod + m - ans * k) % mod + mod) % mod
       << endl;
  return 0;
}
