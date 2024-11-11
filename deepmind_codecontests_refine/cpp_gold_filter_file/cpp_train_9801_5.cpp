#include <bits/stdc++.h>
using namespace std;
template <class T>
void pr(const T& x) {
  cout << x << '\n';
}
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long random_number() { return rng(); }
long long random_number(long long low, long long high) {
  return uniform_int_distribution<long long>(low, high)(rng);
}
bool is_down(char x) { return ('a' <= x && x <= 'z'); }
bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
bool is_digit(char x) { return ('0' <= x && x <= '9'); }
long long bigmod(long long a, long long p, long long m) {
  long long res = 1, x = a % m;
  while (p) {
    if (p & 1) res = (res * x) % m;
    x = (x * x) % m;
    p >>= 1;
  }
  return res;
}
long long inv(long long a, long long p) { return bigmod(a, p - 2, p); }
long long inv_euclid(long long a, long long m) {
  long long m0 = m;
  long long y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long q = a / m;
    long long t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[n];
  long long sum = 0;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n, greater<int>());
  int m;
  cin >> m;
  int mn = std::numeric_limits<int>::max();
  int q[m];
  for (int i = 0; i < (m); i++) {
    cin >> q[i];
    cout << sum - a[q[i] - 1] << endl;
  }
}
