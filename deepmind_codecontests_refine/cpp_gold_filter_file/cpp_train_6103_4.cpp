#include <bits/stdc++.h>
using namespace std;
const long long N = 5e3 + 5;
long long n, a[N], b[N], p[N], k[N], v[N], res[N], ans;
long long query(long long x, long long y) {
  printf("? %lld %lld\n", x, y), fflush(stdout);
  return scanf("%lld", &x), x;
}
bool solve(long long x) {
  p[0] = x;
  for (long long i = 1; i < n; i++) p[i] = p[0] ^ v[i];
  for (long long i = 0; i < n; i++)
    if (p[i] < 0 || p[i] > n - 1) return 0;
  for (long long i = 0; i < n; i++) k[p[i]] = i;
  for (long long i = 0; i < n; i++)
    if (k[i] < 0 || k[i] > n - 1 || k[i] != (p[0] ^ a[i])) return 0;
  for (long long i = 0; i < n; i++) res[i] = p[i];
  return 1;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) a[i] = query(0, i);
  for (long long i = 1; i < n; i++) b[i] = query(i, 0);
  for (long long i = 0; i < n; i++) v[i] = a[0] ^ b[i];
  for (long long i = 0; i < n; i++)
    if (solve(i)) ans++;
  printf("!\n%lld\n", ans);
  for (long long i = 0; i < n; i++)
    printf("%lld%c", res[i], i == n - 1 ? '\n' : ' ');
  return 0;
}
