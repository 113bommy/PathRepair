#include <bits/stdc++.h>
using namespace std;
int n, m, mod, tot, num[100], d[50000], l, ans[50000];
int pri[25] = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
               43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
long long a[20000], f[5000000], c[50000];
string s[50000];
int power(int base, int index) {
  int ret = 1, tmp = base;
  for (; index; index >>= 1, tmp *= tmp)
    if (index & 1) ret *= tmp;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> d[i] >> s[i] >> c[i];
  for (int i = 0, j; i < 25; i = j + 1) {
    mod = 1;
    for (j = i; j < 25; ++j) {
      mod *= pri[j];
      if (mod > 1000000) break;
    }
    for (int d = 2; d <= 16; ++d) {
      int len = 0;
      for (int x = n; x; x /= d) len++;
      tot = power(d + 1, len);
      for (int k = 0, o, p; k < tot; ++k) {
        f[k] = 1;
        for (o = k, !k ? l = 1, num[0] = 0 : l = 0; o; o /= d + 1)
          num[l++] = o % (d + 1);
        for (o = l - 1; o >= 0; --o)
          if (num[o] == d) break;
        if (o == -1) {
          p = 0;
          for (o = l - 1; o >= 0; --o) p *= d, p += num[o];
          if (p < n) f[k] *= a[p] % mod, f[k] %= mod;
        } else {
          p = power(d + 1, o);
          for (o = 1; o <= d; ++o) f[k] *= f[k - o * p], f[k] %= mod;
        }
      }
      for (int k = 0, o, p, q; k < m; ++k) {
        if (::d[k] == d && !ans[k]) {
          o = 0;
          p = s[k].length();
          for (q = 0; p - q > len; q++)
            if (s[k][q] != '?' && s[k][q] != '0')
              ;
          if (p - q > len) continue;
          for (; q < p; ++q)
            o = o * (d + 1) +
                (s[k][q] == '?'
                     ? d
                     : (s[k][q] >= 'A' ? s[k][q] - 'A' + 10 : s[k][q] - '0'));
          for (p = i; p <= j; ++p)
            if ((f[o] + c[k]) % pri[p] == 0) {
              ans[k] = pri[p];
              break;
            }
        }
      }
    }
  }
  for (int i = 0; i < m; ++i) cout << (ans[i] ? ans[i] : -1) << endl;
  return 0;
}
