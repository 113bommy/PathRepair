#include <bits/stdc++.h>
using namespace std;
const vector<vector<long long> > fib_matrix1 = {{0, 1}, {0, 0}};
const vector<vector<long long> > fib_matrix2 = {{0, 1}, {1, 1}};
long long n, k, l, mod;
vector<vector<long long> > zero(int n, int m) {
  return vector<vector<long long> >(n, vector<long long>(m, 0));
}
vector<vector<long long> > identity(int n) {
  vector<vector<long long> > ret = zero(n, n);
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}
vector<vector<long long> > multiply(const vector<vector<long long> > &a,
                                    const vector<vector<long long> > &b) {
  vector<vector<long long> > ret = zero(a.size(), b[0].size());
  for (long long i = 0; i < a.size(); i++)
    for (long long k = 0; k < a[0].size(); k++)
      for (long long j = 0; j < b[0].size(); j++)
        ret[i][j] += a[i][k] * b[k][j], ret[i][j] %= mod;
  return ret;
}
vector<vector<long long> > pow(const vector<vector<long long> > a,
                               long long k) {
  if (k == 0) return identity(a.size());
  if (k % 2 == 1) return multiply(a, pow(a, k - 1));
  return pow(multiply(a, a), k / 2);
}
long long fibMatrix(long long n) {
  if (n <= 1) return n;
  vector<vector<long long> > ret =
      multiply(fib_matrix1, pow(fib_matrix2, n - 1));
  return ret[0][1];
}
long long fast(long long b, long long e) {
  if (!e) return 1;
  return (e & 1 ? b : 1) * fast(b * b % mod, e >> 1);
}
int main() {
  cin >> n >> k >> l >> mod;
  if (mod == 1 || l < 63 && (1ll << l) <= k) return puts("0");
  if (l == 0) {
    if (k == 0) return puts("1");
    return puts("0");
  }
  long long pow2 = fast(2, n);
  long long fib = fibMatrix(n + 2);
  long long out = 1;
  for (int i = 0; i < l; i++) {
    if (((k >> i) & 1) == 0)
      out = out * fib % mod;
    else
      out = out * (pow2 - fib) % mod;
    if (out < 0) out += mod;
  }
  cout << out << '\n';
  return 0;
}
