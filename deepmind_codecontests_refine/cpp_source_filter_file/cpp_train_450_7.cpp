#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long somme(long long a, long long b) { return (a + b) % MOD; }
long long produit(long long a, long long b) { return (a * b) % MOD; }
long long powmod(long long x, long long n) {
  long long res = 1, y;
  if (n == 0) return 1;
  if (n == 1) return x;
  if (n & 1) res = x % MOD;
  y = powmod(x, n / 2);
  return produit(res, produit(y, y));
}
int main() {
  long long inv[2010];
  int i, j;
  long long n, k, a[2010], b[2010], comb;
  cin >> n >> k;
  for (i = 1; i < 2010; i++) inv[i] = powmod(i, MOD - 2);
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = 0;
  }
  if (!k) {
    for (i = 0; i < n; i++) {
      if (i) cout << " ";
      cout << a[i];
    }
    cout << endl;
    return 0;
  }
  k--;
  comb = 1;
  for (i = 0; i < n; i++) {
    for (j = i; j < n; j++) {
      b[j] = somme(b[j], produit(comb, a[i]));
    }
    comb = produit(inv[i + 1], produit(comb, k + i + 1));
  }
  for (i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
  return 0;
}
