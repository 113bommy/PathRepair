#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5, ha = 1e9 + 7;
long long n, mx;
long long a[N], f[N], c[N];
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  return s * w;
}
inline long long lowbit(long long x) { return x & (-x); }
inline long long query(long long x) {
  long long ret = 0;
  while (x) ret = (ret + c[x]) % ha, x -= lowbit(x);
  return ret;
}
inline void updata(long long x, long long val) {
  while (x <= mx) c[x] = (c[x] + val) % ha, x += lowbit(x);
  return;
}
signed main() {
  n = read();
  for (long long i = 1; i <= n; ++i) a[i] = read(), mx = max(a[i], mx);
  for (long long i = 1; i <= n; ++i) {
    long long t = query(a[i]);
    updata(a[i], -f[a[i]]);
    f[a[i]] = (t * a[i] % ha + a[i]) % ha;
    updata(a[i], f[a[i]]);
  }
  printf("%lld", query(mx) % ha);
  return 0;
}
