#include <bits/stdc++.h>
using namespace std;
template <typename _typer>
inline _typer read() {
  _typer init = 0;
  char ch = getchar(), k = 0;
  for (; !isdigit(ch); ch = getchar()) k = (ch == '-');
  for (; isdigit(ch); ch = getchar())
    init = (init << 3) + (init << 1) + (ch ^ 48);
  return k ? -init : init;
}
const long long N = 2005, INF = 1e9;
const long long Mod = 1e9 + 7;
long long Fac[N], Inv[N];
long long Pow(long long x, long long k) {
  long long res = x, ans = 1;
  while (k) {
    if (k & 1) ans = ans * res % Mod;
    res = res * res % Mod, k >>= 1;
  }
  return ans;
}
long long C(int n, int m) {
  if (m > n) return 0;
  return Fac[n] * Inv[m] % Mod * Inv[n - m] % Mod;
}
int main() {
  int n = read<int>(), m = read<int>(), k = read<int>();
  Fac[0] = Inv[0] = 1;
  for (register int i = (1), iend = (n); i <= iend; ++i)
    Fac[i] = Fac[i - 1] * i % Mod, Inv[i] = Pow(Fac[i], Mod - 2);
  printf("%lld\n", C(n - 1, k << 1) * C(m - 1, k << 1) % Mod);
  return 0;
}
