#include <bits/stdc++.h>
using namespace std;
const long long maxm = 8e6 + 9;
const long long maxn = 1e7 + 9;
const long long mod = 1e9 + 7;
const long long inf = 0x3f3f3f3f;
const long long base = 131;
const double eps = 1e-4;
long long n;
long long vis[maxn];
long long ans1, ans2, lcm = 1e18;
long long read() {
  long long a = 1, b = 0;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') a = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    b = (b << 1) + (b << 3) + (c ^ '0');
    c = getchar();
  }
  return a * b;
}
void print(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
signed main() {
  long long u;
  n = read();
  for (long long i = (1); i <= (n); ++i) {
    u = read();
    if (vis[u] && u < lcm) {
      lcm = u, ans1 = vis[u], ans2 = i;
    } else
      vis[u] = i;
  }
  long long val, pos;
  for (long long i = (1); i <= (1e7); ++i) {
    if (i >= lcm) break;
    val = pos = 0;
    for (long long j = i; j <= (1e7); j += i) {
      if (!vis[j]) continue;
      if (!val)
        val = j, pos = vis[j];
      else {
        if (lcm > 1LL * val * j / i)
          lcm = 1LL * val * j / i, ans1 = vis[j], ans2 = vis[val];
      }
    }
  }
  if (ans1 > ans2) swap(ans1, ans2);
  print(ans1);
  putchar(' ');
  ;
  print(ans2);
  return 0;
}
