#include <bits/stdc++.h>
using namespace std;
long n, a[100100], b[100100], f[2 * 100100], g[10], h;
void read() {
  cin >> n;
  h = (n + 1) / 2;
  f[0] = 0;
  for (long i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    f[++f[0]] = a[i];
    f[++f[0]] = b[i];
  }
  sort(f + 1, f + (f[0] + 1));
}
void findpos(void) {
  g[0] = 0;
  for (long i = 1, j, t; i <= f[0];) {
    j = i;
    t = 0;
    while (i <= f[0] && f[j] == f[i]) {
      ++i;
      ++t;
    }
    if (t >= h) g[++g[0]] = f[j];
  }
}
long findval(long x) {
  long u = 0, d = 0;
  for (long i = 0; i < n; ++i)
    if (a[i] == x)
      ++u;
    else if (b[i] == x)
      ++d;
  if (u + d < h) return 10000000;
  if (u >= h) return 0;
  return h - u;
}
int main() {
  long ans = 10000000;
  read();
  findpos();
  for (long i = 1; i <= g[0]; ++i) ans = min(ans, findval(g[i]));
  if (ans == 10000000)
    cout << -1;
  else
    cout << ans;
  return 0;
}
