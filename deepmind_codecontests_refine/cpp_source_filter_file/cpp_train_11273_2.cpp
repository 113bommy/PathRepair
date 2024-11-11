#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 3e5 + 9, mod = 998244353;
inline int add(int x, int y) { return x + y >= mod ? x - mod + y : x + y; }
inline int sub(int x, int y) { return x >= y ? x - y : x + mod - y; }
inline int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = 1LL * x * ret % mod;
    x = 1LL * x * x % mod, y >>= 1;
  }
  return ret;
}
int n, a[N];
int main() {
  n = read<int>() * 2;
  for (int i = 1; i <= n; i++) a[i] = read<int>() % mod;
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n / 2; i++) ans = sub(ans, a[i] % mod);
  for (int i = n / 2 + 1; i <= n; i++) ans = add(ans, a[i] % mod);
  for (int i = 1; i <= n; i++) ans = 1LL * ans * i % mod;
  int ifac = 1;
  for (int i = 1; i <= n / 2; i++) {
    ifac = 1LL * ifac * i % mod;
  }
  ifac = qpow(1LL * ifac * ifac % mod, mod - 2);
  printf("%lld\n", 1LL * ifac * ans % mod);
  return 0;
}
}  // namespace run
int main() { return run::main(); }
