#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long base[101][101], ans[101][101];
long long n, k, maxmisp;
long long zc = 0, oc = 0;
void mulans() {
  long long fin[101][101];
  memset(fin, 0, sizeof(fin));
  for (long long i = 0; i <= 100; i++)
    for (long long j = 0; j <= 100; j++)
      for (long long k = 0; k <= 100; k++) {
        fin[i][j] = (ans[i][k] * base[k][j] + fin[i][j]) % mod;
      }
  memcpy(ans, fin, sizeof(fin));
}
void mulbase() {
  long long fin[101][101];
  memset(fin, 0, sizeof(fin));
  for (long long i = 0; i <= 100; i++)
    for (long long j = 0; j <= 100; j++)
      for (long long k = 0; k <= 100; k++) {
        fin[i][j] = (base[i][k] * base[k][j] + fin[i][j]) % mod;
      }
  memcpy(base, fin, sizeof(fin));
}
long long getinv(long long base) {
  long long expo = mod - 2;
  long long ans = 1;
  while (expo) {
    if (expo & 1) ans = ans * base % mod;
    base = base * base % mod;
    expo >>= 1;
  }
  return ans;
}
void calcbase() {
  long long den = 2 * getinv(n * (n - 1) % mod) % mod;
  for (long long i = 0; i <= maxmisp; i++) {
    long long properz = zc - i, propero = oc - i, wrongz, wrongo;
    wrongz = wrongo = i;
    long long a = wrongo * wrongz % mod;
    a = (a * den) % mod;
    long long b = (zc * (zc - 1)) / 2 + (oc * (oc - 1)) / 2 +
                  (wrongz * propero) + (wrongo * properz);
    b %= mod;
    b = (b * den) % mod;
    long long c = properz * propero % mod;
    c = (c * den) % mod;
    long long sum = (a + b + c) % mod;
    if (i > 0) {
      base[i - 1][i] = a;
    }
    base[i][i] = b;
    if (i < maxmisp) base[i + 1][i] = c;
  }
}
void power() {
  for (long long i = 0; i <= 100; i++) ans[i][i] = 1;
  while (k) {
    if (k & 1) mulans();
    mulbase();
    k >>= 1;
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i])
      oc++;
    else
      zc++;
  }
  maxmisp = min(zc, oc);
  long long currmisp = 0;
  for (long long i = 0; i < n; i++) {
    if (v[i] == 0 && i > zc) {
      currmisp++;
    }
  }
  calcbase();
  power();
  cout << ans[0][currmisp];
  return 0;
}
