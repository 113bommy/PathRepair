#include <bits/stdc++.h>
using namespace std;
const int N = 5005, mod = 1e9 + 7, inv2 = 500000004;
int n, k, ans, s[N][N];
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline int mul(int x, int y) { return 1ll * x * y - 1ll * x * y / mod * mod; }
inline int kpow(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = mul(a, a))
    if (k & 1) res = mul(res, a);
  return res;
}
inline int inv(int a) { return kpow(a, mod - 2); }
inline void init() {
  s[0][0] = 1;
  for (register int i = 1; i <= k; ++i)
    for (register int j = 1; j <= i; ++j)
      s[i][j] = add(s[i - 1][j - 1], mul(s[i - 1][j], j));
}
int main() {
  cin >> n >> k;
  init();
  for (register int i = 0, a = 1, b = kpow(2, n); i <= min(n, k);
       b = mul(b, inv2), a = mul(a, n - i), ++i)
    ans = add(ans, mul(mul(s[k][i], a), b));
  cout << ans << endl;
  return 0;
}
