#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200005], p[200005], cnt[200005];
long long ans;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0', c = getchar();
  return x * f;
}
signed main() {
  n = read(), a[0] = read();
  long long l = 1, r = 0, mx;
  for (long long i = 1; i <= n; i++) a[i] = read(), cnt[a[i]]++, p[a[i]] = i;
  for (long long i = 1; i <= n; i++) {
    r = max(r, p[a[i]]), mx = max(mx, cnt[a[i]]);
    if (r == i) ans += (r - l + 1) - mx, mx = 0, l = r + 1, r = 0;
  }
  cout << ans << endl;
  return 0;
}
