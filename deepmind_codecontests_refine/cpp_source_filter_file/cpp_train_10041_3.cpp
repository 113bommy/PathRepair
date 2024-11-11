#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const long long N = 1e5;
long long cnt[N + 10];
struct vote {
  long long a, b;
  bool operator<(const vote &x) const { return b < x.b; }
} v[N + 10];
bool vis[N + 10];
long long n;
long long check(long long x) {
  long long c = 0, cost = 0;
  for (long long i = 1; i <= N; i++) cnt[i] = 0;
  for (long long i = 1; i <= n; i++) {
    if (!v[i].a)
      vis[i] = 1, c++;
    else
      vis[i] = 0;
    cnt[v[i].a]++;
  }
  for (long long i = 1; i <= n; i++)
    if (cnt[v[i].a] >= x && !vis[i])
      c++, cnt[v[i].a]--, vis[i] = 1, cost += v[i].b;
  if (c < x) {
    for (long long i = 1; i <= n; i++) {
      if (!vis[i]) {
        vis[i] = 1;
        c++;
        cost += v[i].b;
      }
      if (c == x) return cost;
    }
  } else
    return cost;
  return 1e18;
}
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) scanf("%lld%lld", &v[i].a, &v[i].b);
  sort(v + 1, v + n + 1);
  long long l = 0, r = 1e6, Ans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2, f = check(mid);
    if (f <= check(mid + 1))
      r = mid - 1, Ans = mid;
    else
      l = mid + 1;
  }
  printf("%lld", Ans);
  return 0;
}
