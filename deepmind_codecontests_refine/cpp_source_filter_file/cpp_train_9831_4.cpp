#include <bits/stdc++.h>
using namespace std;
namespace zzc {
const int maxn = 1e5 + 5;
long long ans = 0;
long long n, m;
long long a[maxn], b[maxn], sum[maxn];
map<long long, bool> pri;
long long p[100005], cnt = 0;
bool vis[100005];
void init() {
  for (register long long i = 2; i <= 100000; i++) {
    if (!vis[i]) {
      p[++cnt] = i;
    }
    for (register long long j = 1; j <= cnt && i * p[j] <= 100000; j++) {
      vis[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool calc(long long x) {
  if (n == 1) return 0;
  long long res = 0;
  for (register long long i = 1; p[i] * p[i] <= x; i++) {
    if (x % p[i]) continue;
    long long tmp = 0;
    while (x % p[i] == 0) {
      x /= p[i];
      tmp++;
    }
    if (pri[p[i]])
      res -= tmp;
    else
      res += tmp;
  }
  if (x > 1) {
    if (pri[x])
      res--;
    else
      res++;
  }
  return res < 0ll;
}
void work() {
  init();
  scanf("%lld%lld", &n, &m);
  for (register int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (register int i = 1; i <= m; i++) {
    scanf("%lld", &b[i]);
    pri[b[i]] = true;
  }
  sum[1] = a[1];
  for (register int i = 2; i <= n; i++) {
    sum[i] = gcd(sum[i - 1], a[i]);
  }
  for (register long long i = n; i >= 1; i--) {
    if (calc(sum[i])) {
      for (register int j = 1; j <= i; j++) {
        a[j] /= sum[i];
        sum[j] /= sum[i];
      }
    }
  }
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; p[j] * p[j] <= a[i]; j++) {
      if (a[i] % p[j]) continue;
      long long tmp = 0;
      while (a[i] % p[j] == 0) {
        a[i] /= p[j];
        tmp++;
      }
      if (pri[p[j]])
        ans -= tmp;
      else
        ans += tmp;
    }
    if (a[i] > 1) {
      if (pri[a[i]])
        ans--;
      else
        ans++;
    }
  }
  printf("%lld\n", ans);
}
}  // namespace zzc
int main() {
  zzc::work();
  return 0;
}
