#include <bits/stdc++.h>
using namespace std;
const int maxn = 2100;
const long long mod = 1e9 + 7;
long long c[maxn][maxn];
long long a[maxn];
long long n, k;
long long pow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
long long niYuan(long long a) { return pow(a, mod - 2); }
int main() {
  while (cin >> n >> k) {
    for (int i = 1; i <= n; ++i) cin >> a[i];
    c[1][0] = 1;
    for (int i = 2; i <= 2000; ++i) {
      long long tmpa = 1, tmpb = 1;
      for (int j = 1; j < i; ++j) {
        (tmpa *= (k + i - 3 - (j - 1))) %= mod;
        (tmpb *= j) %= mod;
      }
      c[i][0] = tmpa * niYuan(tmpb) % mod;
    }
    c[1][1] = 1LL;
    for (int i = 2; i <= n; ++i) {
      for (int j = i; j > 1; --j) c[i][j] = c[i - 1][j - 1];
      c[i][1] = c[i][0] + c[i - 1][1];
    }
    for (int i = 1; i <= n; ++i) {
      long long ans = 0;
      for (int j = 1; j <= i; ++j) ans = (ans + c[i][j] * a[j] % mod) % mod;
      cout << ans << " ";
    }
    cout << endl;
  }
  return 0;
}
