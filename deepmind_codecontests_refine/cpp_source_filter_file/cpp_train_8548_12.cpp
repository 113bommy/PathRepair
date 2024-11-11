#include <bits/stdc++.h>
using namespace std;
namespace fast_IO {
inline int read_int() {
  register int ret = 0, f = 1;
  register char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ret = (ret << 1) + (ret << 3) + int(c - 48);
    c = getchar();
  }
  return ret * f;
}
}  // namespace fast_IO
using namespace fast_IO;
const long long sigma_size = 2;
long long N, K;
long long f[500005];
long long p[500005];
char a[500005];
char b[500005];
inline void init() {
  N = read_int(), K = read_int();
  scanf("%s", b + 1), scanf("%s", a + 1);
  long long cnt = 0;
  long long ans = 0;
  for (register long long i = 1; i <= N; i++) {
    f[i] = a[i] - b[i];
    f[i] += f[i - 1] * 2;
    p[i] = f[i] + 1;
    if (cnt + p[i] - p[i - 1] > K) {
      ans += 1ll * (K - cnt) * (N - i + 1);
      break;
    } else
      ans += 1ll * (p[i] - p[i - 1]) * (N - i + 1);
    cnt += f[i];
  }
  printf("%lld\n", ans);
}
signed main() {
  init();
  return 0;
}
