#include <bits/stdc++.h>
using namespace std;
long long p = 998244353;
long long Denominator(long long a) {
  long long i = p, v = 0, d = 1;
  if (a == 0) return 1;
  while (a > 0) {
    long long t = i / a, x = a;
    a = i % x;
    i = x;
    x = d;
    d = v - t * x;
    v = x;
  }
  v %= p;
  if (v < 0) v = (v + p) % p;
  return v;
}
int main() {
  long long n, res = 1;
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    res *= (n + i);
    res = res % p;
    res *= Denominator(i);
    res = res % p;
  }
  long long sum = 0;
  vector<long long> a(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    sum += a[2 * n - 1 - i] - a[i];
  }
  cout << res * sum % p << endl;
  return 0;
}
