#include <bits/stdc++.h>
using namespace std;
const long long ml = 1e6 + 101;
long long n, m;
long long len, ans;
long long a[ml], d[ml], s[ml], f[ml], g[ml], t[ml];
inline long long read() {
  long long r = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) r = (r << 1) + (r << 3) + (c ^ 48), c = getchar();
  return r * f;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void port(long long x, char s) {
  write(x);
  putchar(s);
}
vector<long long> v;
void add(long long x, long long y) {
  x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  for (; x >= 1; x -= x & -x) t[x] = ((t[x]) > (y) ? (t[x]) : (y));
}
long long ask(long long x) {
  x = lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  long long res = -1;
  for (; x <= m; x += x & -x) res = ((res) > (t[x]) ? (res) : (t[x]));
  return res;
}
int main() {
  n = read();
  for (long long i = 0; i <= n + 1; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) d[i] = read();
  s[0] = 0;
  for (long long i = 1; i <= n; i++) {
    while ((len != 0) && (a[i] - a[f[s[len]]] > 2 * d[s[len]])) len--;
    f[i] = s[len];
    while ((len != 0) && (2 * d[s[len]] + a[f[s[len]]] <= 2 * d[i] + a[f[i]]))
      len--;
    s[++len] = i;
  }
  s[len = 0] = n + 1;
  for (long long i = n; i >= 1; i--) {
    while ((len != 0) && (a[g[s[len]]] - a[i] > 2 * d[s[len]])) len--;
    g[i] = s[len];
    while ((len != 0) && (a[g[s[len]]] - 2 * d[s[len]] >= a[g[i]] - 2 * d[i]))
      len--;
    s[++len] = i;
  }
  for (long long i = 1; i <= n; i++)
    if (a[g[i]] - a[f[i]] <= 2 * d[i]) return port(0, '\n'), 0;
  for (long long i = 1; i <= n; i++)
    if (a[i] - a[f[i]] < 2 * d[i]) v.push_back(2 * d[i] + a[f[i]]);
  sort(v.begin(), v.end());
  v.resize(m = unique(v.begin(), v.end()) - v.begin());
  memset(t, -1, sizeof(t));
  ans = a[n + 1];
  for (long long i = 1; i <= n; i++)
    ans = ((ans) < (a[g[i]] - a[f[i]]) ? (ans) : (a[g[i]] - a[f[i]]));
  for (long long i = 1; i <= n; i++) {
    if (a[g[i]] - a[i] < 2 * d[i]) {
      long long tmp = ask(a[g[i]] - 2 * d[i]);
      if (tmp != -1) ans = ((ans) < (a[i] - tmp) ? (ans) : (a[i] - tmp));
    }
    if (a[i] - a[f[i]] < 2 * d[i]) add(2 * d[i] + a[f[i]], a[i]);
  }
  for (long long i = 1; i <= n; i++) {
    if ((f[i] == 0) && (a[g[i]] - a[i] < 2 * d[i]))
      ans = ((ans) < (a[i]) ? (ans) : (a[i]));
    if ((g[i] == 0) && (a[i] - a[f[i]] < 2 * d[i]))
      ans = ((ans) < (a[n + 1] - a[i]) ? (ans) : (a[n + 1] - a[i]));
  }
  printf("%.4lf", ans * 0.5);
  return 0;
}
