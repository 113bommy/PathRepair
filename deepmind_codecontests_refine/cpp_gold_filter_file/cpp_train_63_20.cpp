#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 31) - 1;
const long long LINF = (1ll << 63) - 1;
const double DINF = numeric_limits<double>::infinity();
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
mt19937 mmtw(MOD);
long long rnd(long long x, long long y) {
  static uniform_int_distribution<long long> d;
  return d(mmtw) % (y - x + 1) + x;
}
template <class T>
T binpow(T n, T k) {
  if (k == 1) return n;
  if (k & 1) return binpow(n, k - 1) * n;
  T a = binpow(n, k / 2);
  return a * a;
}
template <class T>
T fact(T n) {
  if (n == 1) return 1;
  return n * fact(n - 1);
}
int n, k;
int a[105];
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (k % a[i] == 0) {
      cout << (k / a[i]) << endl;
      return 0;
    }
  }
  return 123;
}
