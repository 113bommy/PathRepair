#include <bits/stdc++.h>
using namespace std;
namespace thecold {
const int jzp = 1e9 + 7;
int n, m;
inline int quickpow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % jzp;
    x = x * x % jzp, y >>= 1;
  }
  return ret;
}
inline void main() {
  scanf("%d %d", &n, &m);
  if (m > n) return puts("0"), void();
  printf("%lld\n", 1ll * quickpow(2, m) * quickpow((n + 1) % jzp, m - 1) % jzp *
                       (n - m + 1) % jzp);
}
}  // namespace thecold
int main() {
  thecold::main();
  return 0;
}
