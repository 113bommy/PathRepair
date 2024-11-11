#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int ans, n, m, a, b, fc[N], ifc[N];
int power(int a, int b) {
  int rtr = 1;
  for (; b > 0; b /= 2, a = 1ll * a * a % mod)
    if (b % 2) rtr = 1ll * rtr * a % mod;
  return rtr;
}
void Pre() {
  fc[0] = ifc[0] = 1;
  for (int i = 1; i < N - 4; i++)
    fc[i] = 1ll * fc[i - 1] * i % mod, ifc[i] = 1ll * power(fc[i], mod - 2);
}
int ch(int x, int y) {
  if (y < 0 || x > y) return 0;
  return 1ll * fc[y] * ifc[x] % mod * ifc[y - x] % mod;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Pre();
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= min(n - 1, m); i++) {
    int rtr = ch(i - 1, m - 1);
    rtr = 1ll * rtr * power(m, (n - 1) - i) % mod;
    rtr = 1ll * rtr * ch(i - 1, n - 2) % mod;
    rtr = 1ll * rtr * fc[i - 1] % mod;
    if (i != n - 1)
      rtr = 1ll * rtr * (1ll * (i + 1) * power(n, n - (i + 1) - 1) % mod) % mod;
    ans = (ans + rtr) % mod;
  }
  cout << ans;
  return 0;
}
