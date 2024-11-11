#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  return;
  cerr << "prinitng " << second << ": ";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
long long mod = 1e9 + 7;
vc<vc<long long> > mul(vc<vc<long long> > a, vc<vc<long long> > b) {
  long long n = a.size();
  vc<vc<long long> > res(n, vc<long long>(n));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      for (long long k = 0; k < n; k++) {
        res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
      }
    }
  }
  return res;
}
vc<vc<long long> > fast_pow(vc<vc<long long> > a, long long p) {
  if (p == 1) {
    return a;
  }
  if (p == 0) {
    for (long long i = 0; i < a.size(); i++) {
      a[i][i] = 1;
    }
    return a;
  }
  if (p % 2 == 0) {
    return fast_pow(mul(a, a), p / 2);
  }
  return mul(a, fast_pow(a, p - 1));
}
long long f_pow(long long a, long long e) {
  if (e == 0) return 1;
  if (e % 2 == 0) return f_pow((a * a) % mod, e / 2);
  return (a * f_pow(a, e - 1)) % mod;
}
long long inv(long long a) { return f_pow(a, mod - 2); }
long long binom(long long n, long long k) {
  long long b = 1;
  for (long long i = k + 1; i <= n; i++) {
    b = (b * i) % mod;
  }
  for (long long i = 1; i <= n - k; i++) {
    b = (b * inv(i)) % mod;
  }
  return b;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vc<vc<long long> > a(2 * k + 3, vc<long long>(2 * k + 3));
  for (long long i = 0; i <= k; i++) {
    for (long long j = 0; j <= i; j++) {
      a[i][j] = binom(i, j);
      a[i][j + k + 1] = binom(i, j) * f_pow(2, i - j);
    }
  }
  for (long long i = 0; i <= k; i++) {
    a[i + k + 1][i] = 1;
  }
  a[2 * k + 2][k] = 1;
  a[2 * k + 2][2 * k + 2] = 1;
  for (long long i = 0; i < a.size(); i++) {
    print(a[i], "\n");
  }
  vc<long long> b(2 * k + 3);
  for (long long i = 0; i <= k; i++) {
    b[i] = f_pow(2, i + 1);
  }
  for (long long i = 0; i <= k; i++) {
    b[i + k + 1] = 1;
  }
  vc<vc<long long> > res = fast_pow(a, n - 1);
  for (long long i = 0; i < res.size(); i++) {
    print(res[i], "\n");
  }
  long long sum = 0;
  for (long long i = 0; i < b.size(); i++) {
    sum += b[i] * res[2 * k + 2][i];
  }
  sum = (mod + sum + 1) % mod;
  if (n == 1) {
    cout << "1\n";
  } else {
    cout << sum << "\n";
  }
}
