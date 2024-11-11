#include <bits/stdc++.h>
using namespace std;
struct pp {
  long long x, y;
};
const int base = 1000 * 1000 * 1000;
const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int inf = 1e11;
const int mod = 1e6 + 3;
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long binpow(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a, res %= mod;
    a *= a, a %= mod;
    n >>= 1;
  }
  return res % mod;
}
long long t, n, m, k, x, y, z, cnt, maxx = -inf, minn = inf, a[222222],
                                    c[222222], sum;
long long b[222222];
int main() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    if (!i)
      sum = n * (n - 1) / 2;
    else {
      sum += i;
      sum -= n - i;
    }
    maxx = max(maxx, sum);
    minn = min(minn, sum);
  }
  sum = 0;
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    ;
    sum += max(x * n + y * maxx, x * n + y * minn);
  }
  cout << fixed << setprecision(11) << (long double)(sum) / (long double)(n);
  return 0;
}
