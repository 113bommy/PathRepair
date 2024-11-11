#include <bits/stdc++.h>
using namespace std;
int n, x, mx, p[10000010], prime[10000010], cnt;
long long f[10000010], l, r, mid, ans;
inline int read() {
  register int x = 0, ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
inline void shake() {
  for (register int i = 2; i <= 10000000; i++) {
    if (!p[i]) prime[++cnt] = i;
    for (register int j = 1; j <= cnt && i * prime[j] <= 10000000; j++) {
      p[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
inline bool check(long long x) {
  for (register int i = 1; i <= cnt; i++) {
    register long long temp = x;
    int tot = 0;
    while (temp) tot += temp /= prime[i];
    if (f[prime[i]] > tot) return 0;
  }
  return 1;
}
int main() {
  shake();
  n = read();
  for (register int i = 1; i <= n; i++)
    f[x = read()]++, mx = max(x, mx), r += x;
  for (register int i = mx; i; i--) f[i - 1] += f[i];
  for (register int i = mx; i; i--)
    if (p[i]) {
      f[p[i]] += f[i];
      f[i / p[i]] += f[i];
    }
  while (l <= r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid - 1, ans = mid;
    else
      l = mid + 1;
  }
  cout << max(1ll, ans) << endl;
  return 0;
}
