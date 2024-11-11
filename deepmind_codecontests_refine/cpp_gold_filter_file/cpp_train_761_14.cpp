#include <bits/stdc++.h>
using namespace std;
long long int binomialCoeff(long long int n, long long int k) {
  long long int C[n + 1][k + 1];
  long long int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= min(i, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j - 1] % 1000000007 + C[i - 1][j] % 1000000007) %
                  1000000007;
    }
    C[i][j] = C[i][j] % 1000000007;
  }
  return C[n][k] % 1000000007;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int power(long long int base, long long int exp) {
  long long int res = 1;
  while (exp > 0) {
    if (exp % 2 == 1) res = (res * base) % 1000000007;
    base = (base * base) % 1000000007;
    exp /= 2;
  }
  return res % 1000000007;
}
void ghost() {
  long long int n, m, k = 0, flag = 0, s = 0, l = 0, c = 0, q, p = 0, i, j,
                      t = 0, x, y;
  cin >> n;
  set<pair<long long int, long long int> > v;
  long long int a[n], b[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    v.insert(make_pair(a[i], b[i]));
  }
  for (i = 0; i < n; i++) {
    k = a[i];
    l = b[i];
    for (j = i + 1; j < n; j++) {
      if ((k + a[j]) % 2 == 0 && (l + b[j]) % 2 == 0) {
        p = (k + a[j]) / 2;
        q = (l + b[j]) / 2;
        if (v.count({p, q})) c++;
      }
    }
  }
  cout << c;
}
signed main() {
  int test = 1;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while (test--) ghost();
  return 0;
}
