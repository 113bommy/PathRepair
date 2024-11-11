#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  long long minblocks = INT_MAX;
  long long maxblocks = INT_MIN;
  for (long long i = 1; i * i * i <= n; i++) {
    if (n % i == 0) {
      for (long long j = i; j * j <= n / i; j++) {
        if ((n / i) % j == 0) {
          long long k = n / i;
          k /= j;
          long long x = (i + 1) * (j + 2) * (k + 2);
          long long y = (j + 1) * (i + 2) * (k + 2);
          long long z = (k + 1) * (j + 2) * (i + 2);
          minblocks = min(minblocks, x - n);
          minblocks = min(minblocks, y - n);
          minblocks = min(minblocks, z - n);
          maxblocks = max(maxblocks, x - n);
          maxblocks = max(maxblocks, y - n);
          maxblocks = max(maxblocks, z - n);
        }
      }
    }
  }
  cout << minblocks << " " << maxblocks;
}
