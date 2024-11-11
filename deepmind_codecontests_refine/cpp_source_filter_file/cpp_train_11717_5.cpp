#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  int f = 0, c = getchar();
  x = 0;
  while (!isdigit(c)) f |= c == 45, c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (f) x = -x;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
namespace run {
const long long mod = 1e9 + 7;
long long ans = 2ll;
int n;
bool flg;
inline long long power(long long a, long long b) {
  long long res = 1ll;
  while (b) {
    if (b & 1ll) res = res * a % mod;
    a = a * a % mod;
    b >>= 1ll;
  }
  return res;
}
inline int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) {
    long long x;
    read(x);
    if (x & 1ll) flg = true;
    ans = power(ans, x);
  }
  ans = ans * power(2ll, mod - 2ll) % mod;
  if (flg)
    printf("%lld/%lld\n", (ans - 1ll + mod) * power(3ll, mod - 2ll) % mod, ans);
  else
    printf("%lld/%lld\n", (ans + 1ll) * power(3ll, mod - 2ll) % mod, ans);
  return 0;
}
}  // namespace run
int main() { return run ::main(); }
