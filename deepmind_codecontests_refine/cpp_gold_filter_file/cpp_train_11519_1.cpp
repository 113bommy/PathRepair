#include <bits/stdc++.h>
using namespace std;
const long long MX = 1e5 + 4;
long long n, m, k, arr[MX];
int32_t main() {
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) cin >> arr[i];
  if (n % 2 == 0) {
    return cout << 0, 0;
  }
  if (n == 1) {
    long long ret = min(m * k, arr[0]);
    return cout << ret, 0;
  }
  if ((n + 1) / 2 > m) {
    return cout << 0, 0;
  }
  long long time_for_one = (n + 1) / 2;
  long long times = m / time_for_one;
  long long mn = MX;
  for (long long i = 0; i < n; i += 2) mn = min(mn, arr[i]);
  cout << min(mn, k * times);
  return 0;
}
