#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const long double eps = 1e-9;
long long mod = 998244353;
const long long N = 1e6 + 5;
long long n;
char a[N], b[N];
long long ans = 0;
signed main() {
  scanf("%lld", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (long long i = 1; i <= n / 2; i++) {
    long long j = n - i + 1;
    long long x1 = a[i], x2 = a[j], y1 = b[i], y2 = b[j];
    if (x1 == y1 && x2 == y2) continue;
    if (x1 == x2 && y1 == y2) continue;
    if (x1 == y2 && x2 == y1) continue;
    long long fg = 0;
    if (x1 != y1 && x1 != y2) fg++;
    if (x2 != y1 && x2 != y2) fg++;
    if (x1 != x2) fg++;
    if (fg == 3)
      ans += 2;
    else
      ans++;
  }
  if (n & 1) {
    long long t = n / 2 + 1;
    if (a[t] != b[t]) ans++;
  }
  cout << ans;
}
