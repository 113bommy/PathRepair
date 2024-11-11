#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long power(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret *= a;
    a *= a;
    if (ret >= MOD) ret %= MOD;
    if (a >= MOD) a %= MOD;
    b >>= 1;
  }
  return ret;
}
long long invmod(long long x) { return power(x, MOD - 2); }
long long gcd(long long a, long long b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
long long seive(long long n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  long long i = 5;
  while (i * i <= n) {
    if (i * n == 0 || i * (n + 2) == 0) return 0;
  }
  return 1;
}
int main() {
  int n, k;
  cin >> n >> k;
  long long z = n * n;
  long long k1 = n - k;
  long long sum = 0;
  long long a[n + 1][n + 1];
  int count = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      a[i][j] = count++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = k; j < n; j++) {
      a[i][j] = count++;
    }
  }
  for (int i = 0; i < n; i++) {
    sum += a[i][k - 1];
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}
