#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e12 + 3;
const long long MAXN = (long long)2e3 + 5;
struct Node {
  long long t, c, w, v;
} a[MAXN];
long long f[MAXN], n;
signed main() {
  scanf("%lld", &n);
  long long maxx = -1;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &a[i].t, &a[i].c);
    a[i].w = a[i].t + 1;
    a[i].v = a[i].c;
    maxx = max(maxx, n + a[i].w);
  }
  for (long long i = 0; i <= maxx; i++) f[i] = INF;
  f[0] = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = maxx; j >= a[i].w; j--) {
      f[j] = min(f[j], f[j - a[i].w] + a[i].v);
    }
  }
  long long ans = INF;
  for (long long i = n; i <= maxx; i++) ans = min(ans, f[i]);
  printf("%lld", ans);
  return 0;
}
