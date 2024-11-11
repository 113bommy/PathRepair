#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5;
long long f[MAXN + 10], cnt[MAXN + 10];
long long get_fa(long long);
inline long long read();
signed main() {
  long long n, m, p;
  n = read(), m = read(), p = read();
  for (register long long i = 1; i <= n; ++i) f[i] = i, cnt[i] = 1;
  for (register long long i = 1; i <= m; ++i) {
    long long x = read(), y = read();
    x = get_fa(x), y = get_fa(y);
    if (x == y) continue;
    f[y] = x;
    cnt[x] += cnt[y];
  }
  long long sum = 0, ans = 1, num = 1;
  for (register long long i = 1; i <= n; ++i) {
    if (f[i] == i) {
      ++sum;
      ans = ans * cnt[i] % p;
    }
  }
  if (sum == 1) {
    printf("1\n");
    return 0;
  }
  for (register long long i = 1; i <= sum - 2; ++i) num = num * n % p;
  ans = ans * num % p;
  printf("%lld\n", ans);
  return 0;
}
inline long long read() {
  long long x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c & 15), c = getchar();
  return x;
}
long long get_fa(long long x) {
  if (f[x] == x) return x;
  return f[x] = get_fa(f[x]);
}
