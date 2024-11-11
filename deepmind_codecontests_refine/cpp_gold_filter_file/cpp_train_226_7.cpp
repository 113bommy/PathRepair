#include <bits/stdc++.h>
using namespace std;
long long d, x, y;
void extendedEuclid(long long A, long long B) {
  if (B == 0) {
    d = A;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(B, A % B);
    long long temp = x;
    x = y;
    y = temp - (A / B) * y;
  }
}
long long modInverse(long long A, long long M) {
  extendedEuclid(A, M);
  return (x % M + M) % M;
}
long long expo(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0) return expo((a * a) % m, b / 2, m);
  return (a * expo((a * a) % m, (b - 1) / 2, m)) % m;
}
int32_t main() {
  long long tt = 1;
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n), b(n);
    long long s1 = 0, s2 = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      s1 += a[i];
    }
    for (long long i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(b.begin(), b.end());
    long long mi = INT_MAX;
    for (long long i = 0; i < n; i++) {
      long long x = (b[i] - a[0] + m) % m;
      vector<long long> t;
      for (long long i = 0; i < n; i++) t.push_back((a[i] + x) % m);
      sort(t.begin(), t.end());
      if (t == b) mi = min(mi, x);
    }
    cout << mi << endl;
  }
  return 0;
}
