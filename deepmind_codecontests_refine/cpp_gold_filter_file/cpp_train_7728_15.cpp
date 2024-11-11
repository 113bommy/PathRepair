#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 17;
long long t;
long long a[maxn];
long long n, k;
long long qsm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a % 998244353 + 998244353) % 998244353;
    a = a * a % 998244353;
    b = b >> 1;
  }
  return ans;
}
int main() {
  t = 1;
  while (t--) {
    cin >> n;
    a[n] = 10;
    a[n - 1] = 180;
    for (long long i = n - 2; i > 0; i--) {
      a[i] = ((a[i + 1] +
               (long long)81 * qsm((long long)10, n - 2 - i) % 998244353)) %
                 998244353 * (long long)10 % 998244353 +
             998244353;
      a[i] = a[i] % 998244353;
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
  }
  return 0;
}
