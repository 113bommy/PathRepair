#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int ksm(int x, int y) {
  return y == 1
             ? x
             : 1ll * ksm(1ll * x * x % mod, y >> 1) * ((y & 1) ? x : 1) % mod;
}
int k, A, h;
int a[20], b[20], ans[40];
set<pair<int, int>> S1, S2;
inline void sol(int t, int num, int win) {
  for (int i = 1; i <= (1 << k - 1); i++) b[i] = i + num;
  for (int i = k - 2; i >= 0; i--) {
    for (int j = 1; j <= (1 << i); j++) {
      ans[b[j * 2 - !(t & 1)]] = (1 << i + 1);
      b[j] = b[j * 2 - (t & 1)];
      t >>= 1;
    }
  }
  ans[b[1]] = win;
}
inline void pr(void) {
  for (int i = 1; i <= (1 << k); i++) printf("%d ", ans[i] + 1);
  exit(0);
}
int main() {
  scanf("%d%d%d", &k, &A, &h);
  h = 1ll * h * ksm(A, mod - 2) % mod;
  int sum = ((1 << (k - 1)) - 1), n = (1 << (k - 1));
  for (int _i = 0; _i < (1 << sum); _i++) {
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    int t = _i, soc = 0;
    for (int i = k - 2; i >= 0; i--) {
      int tmp = ksm(A, 1 << i + 1);
      for (int j = 1; j <= (1 << i); j++) {
        soc = (soc + 1ll * a[j * 2 - !(t & 1)] * tmp % mod) % mod;
        a[j] = a[j * 2 - (t & 1)];
        t >>= 1;
      }
    }
    soc = (soc + a[1]) % mod;
    S1.insert(make_pair(soc, _i));
    soc = (soc - a[1] + mod) % mod;
    soc = (soc + 1ll * a[1] * A % mod) % mod;
    S2.insert(make_pair(soc, _i));
  }
  set<pair<int, int>>::iterator it;
  for (int _i = 0; _i < (1 << sum); _i++) {
    for (int i = 1; i <= n; i++) {
      a[i] = i + (1 << k - 1);
    }
    int t = _i, soc = 0;
    for (int i = k - 2; i >= 0; i--) {
      int tmp = ksm(A, 1 << i + 1);
      for (int j = 1; j <= (1 << i); j++) {
        soc = (soc + 1ll * a[j * 2 - !(t & 1)] * tmp % mod) % mod;
        a[j] = a[j * 2 - (t & 1)];
        t >>= 1;
      }
    }
    soc = (soc + a[1]) % mod;
    it = S2.lower_bound(make_pair((h - soc + mod) % mod, 0));
    if (it != S2.end() && ((*it).first + soc) % mod == h) {
      sol((*it).second, 0, 1);
      sol(_i, 1 << k - 1, 0);
      pr();
    }
    soc = (soc - a[1] + mod) % mod;
    soc = (soc + 1ll * a[1] * A % mod) % mod;
    it = S1.lower_bound(make_pair((h - soc + mod) % mod, 0));
    if (it != S1.end() && ((*it).first + soc) % mod == h) {
      sol((*it).second, 0, 0);
      sol(_i, 1 << k - 1, 1);
      pr();
    }
  }
  puts("-1");
  return 0;
}
