#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const long long maxn = 1e6 + 10;
long long n, k;
inline void work() {
  n = read(), k = read();
  if (1ll * n * (n + 1) / 2 > k) return (void)puts("-1");
  long long sum = 0;
  printf("%lld\n", min(k, 1ll * n * (n / 2 + 1) +
                              1ll * ((n - 1) / 2 + 1) * ((n - 1) / 2) / 2 * 2));
  for (long long i = 1; i <= n; i++) printf("%lld ", i), sum += i;
  puts("");
  long long l = 1, r = n;
  for (long long i = 1; i <= n; i++)
    if (sum + r - i > k)
      printf("%lld ", l), l++;
    else
      printf("%lld ", r), sum += r - i, r--;
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
