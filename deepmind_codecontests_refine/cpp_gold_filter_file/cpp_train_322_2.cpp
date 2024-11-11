#include <bits/stdc++.h>
using namespace std;
const int hgs = 998244353, N = 5500;
int fac[N], inv[N], n = 5200, s, p, r, inv2[N];
int qpow(int A, int B) {
  int C = 1;
  for (; B; B >>= 1, A = 1ll * A * A % hgs)
    if (B & 1) C = 1ll * A * C % hgs;
  return C;
}
void prep() {
  fac[0] = inv[0] = 1;
  for (register int i = (1); i <= (n); ++i) fac[i] = 1ll * i * fac[i - 1] % hgs;
  inv[n] = qpow(fac[n], hgs - 2);
  for (register int i = (n - 1); i >= (1); --i)
    inv[i] = 1ll * (i + 1) * inv[i + 1] % hgs;
  for (register int i = (1); i <= (n); ++i) inv2[i] = qpow(i, hgs - 2);
}
void upd(int &x, int y) { x = (x + y) % hgs; }
void ret(int &x) { x = (x % hgs + hgs) % hgs; }
int C(int A, int B) {
  if (A < 0 || B < 0 || B - A < 0) return 0;
  return 1ll * fac[B] * inv[A] % hgs * inv[B - A] % hgs;
}
int S(int A, int B) { return C(B - 1, A + B - 1); }
int calc(int rs, int rsp, int ove) {
  if (rs == 0) return 1;
  int ans = 0;
  long long nw = 1;
  for (register int i = (0); i <= (rsp); ++i) {
    if (i * ove > rs) break;
    upd(ans, 1ll * nw * S(rs - i * ove, rsp) * C(i, rsp) % hgs);
    ret(ans);
    nw = -nw;
  }
  return ans;
}
int g(int x) {
  int rs = s - x, ans = 0;
  for (register int i = (0); i <= (p - 1); ++i) {
    if (i * x > rs) break;
    if ((p - 1 - i) * (x - 1) + (i + 1) * x < s) continue;
    upd(ans, 1ll * inv2[i + 1] * calc(rs - i * x, p - (i + 1), x) % hgs *
                 C(i, p - 1) % hgs);
  }
  return ans;
}
signed main() {
  int ans = 0;
  cin >> p >> s >> r;
  prep();
  for (register int i = (r); i <= (s); ++i) upd(ans, g(i));
  int t = S(s - r, p);
  cout << 1ll * ans * qpow(t, hgs - 2) % hgs << '\n';
  return 0;
}
