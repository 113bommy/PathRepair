#include <bits/stdc++.h>
using namespace std;
const int REV2 = 500000004;
const int mod = 1e9 + 7;
const int N = 1e6 + 8;
long long fac[N], f[N], ans;
int n, t[N];
void Upd(int x, int v) {
  for (; x <= n; x += x & -x) t[x] += v;
}
int Qry(int x) {
  int v = 0;
  for (; x; x -= x & -x) v += t[x];
  return v;
}
int main() {
  scanf("%d", &n);
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % mod;
  for (int i = 1; i <= n; ++i)
    f[i] = fac[i] * i % mod * (i - 1) * REV2 % mod * REV2 % mod;
  for (int i = 1; i <= n; ++i) Upd(i, 1);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    int k = Qry(x - 1), len = n - i;
    ans = (ans + 1ll * k * f[len] % mod) % mod;
    ans = (ans + 1ll * k * cnt % mod * fac[len] % mod) % mod;
    ans = (ans + 1ll * k * (k - 1) / 2 % mod * fac[len] % mod) % mod;
    cnt = (cnt + k) % mod;
    Upd(x, -1);
  }
  printf("%lld\n", (ans + cnt) % mod);
  return 0;
}
