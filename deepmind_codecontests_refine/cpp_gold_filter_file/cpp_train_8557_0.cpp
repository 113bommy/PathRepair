#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2e5 + 5;
const long double pi = 3.14159265359;
const long long INF = (1LL << 62);
long long n, k, ans;
long long count(long long x, long long ty) {
  if (x > n) return 0;
  long long tmp = 2 - ty;
  for (long long i = 1; x * (1LL << i) <= n; i++) {
    tmp += min(n - x * (1LL << i) + 1, (1LL << (i + 1 - ty)));
  }
  return tmp;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  long long r = n / 2 + 1, l = 1;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (count(mid * 2, 0) < k)
      r = mid;
    else
      l = mid;
  }
  ans = 2 * l;
  if (count(2 * l, 0) < k) ans = 0;
  r = (n - 1) / 2 + 1;
  l = 0;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (count(2 * mid + 1, 1) < k)
      r = mid;
    else
      l = mid;
  }
  if (l * 2 + 1 > ans) ans = l * 2 + 1;
  cout << ans << "\n";
  return 0;
}
