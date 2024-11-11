#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30);
const long long INFLL = (1ll << 60);
const long long MOD = 998244353ll;
void mul_mod(long long& a, long long b) {
  a *= b;
  a %= MOD;
}
void add_mod(long long& a, long long b) {
  a = (a < MOD) ? a : (a - MOD);
  b = (b < MOD) ? b : (b - MOD);
  a += b;
  a = (a < MOD) ? a : (a - MOD);
}
int cnt[10];
long long a[100100];
int main(void) {
  int n, i, d, j, k;
  long long p, b[11], tmp, ans = 0ll;
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    p = a[i];
    d = 0;
    while (p) {
      ++d;
      p /= 10;
    }
    ++cnt[d];
  }
  for (i = 0; i < n; ++i) {
    for (j = 1; j < 10; ++j) {
      b[j] = 0ll;
    }
    p = a[i];
    d = 0;
    while (p) {
      ++d;
      b[d] = p % 10;
      p /= 10;
    }
    for (j = 1; j < d; ++j) {
      tmp = 0ll;
      for (k = 9; k > j; --k) {
        mul_mod(tmp, 10ll);
        add_mod(tmp, b[k]);
      }
      for (k = j; k > 0; --k) {
        mul_mod(tmp, 100ll);
        add_mod(tmp, b[k]);
      }
      mul_mod(tmp, cnt[j]);
      add_mod(ans, tmp);
      tmp = 0ll;
      for (k = 9; k >= j; --k) {
        mul_mod(tmp, 10ll);
        add_mod(tmp, b[k]);
      }
      for (k = (j - 1); k > 0; --k) {
        mul_mod(tmp, 100ll);
        add_mod(tmp, b[k]);
      }
      mul_mod(tmp, 10ll);
      mul_mod(tmp, cnt[j]);
      add_mod(ans, tmp);
    }
    tmp = 0ll;
    for (j = d; j > 0; --j) {
      mul_mod(tmp, 100ll);
      add_mod(tmp, b[j] * 11);
    }
    for (j = d; j < 10; ++j) {
      add_mod(ans, (tmp * cnt[j]) % MOD);
    }
  }
  cout << ans << endl;
  return 0;
}
