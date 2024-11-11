#include <bits/stdc++.h>
using namespace std;
const long long maxn = 60;
long long n;
long long f[maxn][maxn], sum[maxn];
struct node {
  long long a, b;
} e[maxn];
bool cmp(node a, node b) {
  if (a.a == b.b) return a.b > b.b;
  return a.a > b.a;
}
bool check(long long x) {
  memset(f, 60, sizeof(f));
  f[0][0] = 0;
  long long j;
  for (long long i = 1; i <= n; i = j) {
    j = i;
    while (j <= n && e[i].a == e[j].a) j++;
    for (long long k = i; k < j; k++)
      sum[k - i + 1] = sum[k - i] + e[k].a - x * e[k].b;
    for (long long k = 0; k <= n; k++)
      for (long long l = 0; l <= min(k, j - i); l++)
        f[j - 1][k - l + j - i - l] =
            min(f[j - 1][k - l + j - i - l], f[i - 1][k] + sum[j - i - l]);
  }
  for (long long i = 0; i <= n; i++)
    if (f[n][i] <= 0) return true;
  return false;
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &e[i].a);
    e[i].a *= 1000;
  }
  for (long long i = 1; i <= n; i++) scanf("%lld", &e[i].b);
  sort(e + 1, e + 1 + n, cmp);
  long long l = 1, r = 1000000000000, ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
