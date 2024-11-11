#include <bits/stdc++.h>
using namespace std;
long long inf = 1e9;
long long power(long long x, long long n, long long mod) {
  long long res = 1;
  x %= mod;
  while (n) {
    if (n & 1) res = (res * x) % mod;
    x = (x * x) % mod;
    n >>= 1;
  }
  return res % 1000000007;
}
long long dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, d, h;
  cin >> n >> d >> h;
  if (n == 2 && d == 1 && h == 1) {
    cout << "1 2\n";
    return 0;
  }
  if (d < h || d > 2 * h || d > n || h > n || (d <= 1 && h <= 1)) {
    cout << "-1\n";
  } else {
    for (long long i = 1; i <= h; i++) {
      cout << i << " " << i + 1 << '\n';
    }
    long long c = 0;
    long long z = 1, k = 1;
    long long z1 = d - (h + 1);
    if (d == h) {
      while (c < (n - (h + 1))) {
        cout << 2 << " " << h + 1 + k << '\n';
        c++;
        k++;
      }
      return 0;
    }
    while (c < (n - (h + 1))) {
      cout << z << " " << h + 1 + k << '\n';
      c++;
      if (c % (z1 + 1) == 0) {
        z = 1;
        k++;
      } else {
        z = h + 1 + k;
        k++;
      }
    }
  }
  return 0;
}
