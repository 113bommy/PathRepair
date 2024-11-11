#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int n, m, k;
int a[maxn], b[maxn], suma[maxn], sumb[maxn];
unordered_map<int, int> mpa[maxn], mpb[maxn];
inline int read() {
  int x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x;
}
inline void init() {
  for (int i = 1; i <= n; i++) sumb[i] = 0, mpa[i].clear(), mpb[i].clear();
  for (int i = 1; i <= m; i++) sumb[i] = 0, mpa[i].clear(), mpb[i].clear();
}
int main() {
  int T = read();
  while (T--) {
    long long ans = 0;
    n = read(), m = read(), k = read();
    init();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= m; i++) b[i] = read();
    for (int i = 1; i <= k; i++) {
      int x = read(), y = read();
      int px = lower_bound(a + 1, a + 1 + n, x) - a;
      int py = lower_bound(b + 1, b + 1 + m, y) - b;
      if (a[px] != x) ans += suma[px]++ - mpa[px][py]++;
      if (b[py] != y) ans += sumb[py]++ - mpb[px][py]++;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
