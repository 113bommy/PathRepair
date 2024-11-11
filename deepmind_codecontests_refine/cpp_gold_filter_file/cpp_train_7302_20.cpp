#include <bits/stdc++.h>
using namespace std;
void read(long long &x) {
  char ch;
  bool ok;
  for (ok = 0, ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') ok = 1;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  if (ok) x = -x;
}
const long long maxn = 3e5 + 10;
struct oo {
  long long x, y;
} a[maxn], s[maxn];
long long sum, ans, tot, n;
bool flag, vis[maxn];
void add(long long x) {
  for (register long long i = 61; i >= 0; i--)
    if (a[x].y & (1ll << i)) return s[x].y = i, void();
}
signed main() {
  read(n);
  for (register long long i = 1; i <= n; i++) {
    read(a[i].x), read(a[i].y);
    add(i);
    sum += a[i].x;
  }
  if (sum < 0)
    for (register long long i = 1; i <= n; i++) a[i].x = -a[i].x;
  for (register long long i = 0; i <= 61; i++) {
    long long now = 0;
    for (register long long j = 1; j <= n; j++)
      if (s[j].y == i) now += a[j].x;
    if (now > 0) {
      ans += 1ll << i;
      for (register long long j = 1; j <= n; j++)
        if (a[j].y & (1ll << i)) a[j].x = -a[j].x;
    }
  }
  printf("%lld\n", ans);
}
