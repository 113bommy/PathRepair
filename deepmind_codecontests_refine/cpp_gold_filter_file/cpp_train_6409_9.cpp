#include <bits/stdc++.h>
using namespace std;
long long n, m, a[2001000], b[2001000], c[2001000], d[2001000], x, s, ans, k;
inline long long getint() {
  long long w = 0, q = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 1, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? -w : w;
}
int main() {
  cin >> n >> m >> k;
  cin >> x >> s;
  for (long long i = 1; i <= m; i++) a[i] = getint();
  for (long long i = 1; i <= m; i++) b[i] = getint();
  for (long long i = 1; i <= k; i++) c[i] = getint();
  for (long long i = 1; i <= k; i++) d[i] = getint();
  long long ans = n * x;
  a[m + 1] = x;
  for (long long i = 1; i <= m + 1; i++)
    if (s >= b[i]) {
      long long res = s - b[i];
      long long pos = upper_bound(d + 1, d + k + 1, res) - d;
      if (pos == 1) {
        ans = min(ans, n * a[i]);
        continue;
      }
      pos--;
      long long val = n - c[pos];
      val *= a[i];
      ans = min(ans, val);
    }
  cout << ans;
  return 0;
}
