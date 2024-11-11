#include <bits/stdc++.h>
using namespace std;
const int RLEN = 1 << 20 | 1;
inline char gc() {
  static char ibuf[RLEN], *ib, *ob;
  (ib == ob) && (ob = (ib = ibuf) + fread(ibuf, 1, RLEN, stdin));
  return (ib == ob) ? EOF : *ib++;
}
inline int read() {
  char ch = gc();
  int res = 0;
  bool f = 1;
  while (!isdigit(ch)) f ^= ch == '-', ch = gc();
  while (isdigit(ch)) res = (res + (res << 2) << 1) + (ch ^ 48), ch = gc();
  return f ? res : -res;
}
inline int readstring(char *s) {
  int top = 0;
  char ch = gc();
  while (isspace(ch)) ch = gc();
  while (!isspace(ch) && ch != EOF) s[++top] = ch, ch = gc();
  return top;
}
template <class tp>
inline void chemx(tp &a, tp b) {
  a < b ? a = b : 0;
}
template <class tp>
inline void chemn(tp &a, tp b) {
  a > b ? a = b : 0;
}
const int N = 100005;
int n, m, K, p, h[N], a[N], t[N];
inline bool check(long long lim) {
  long long tim = 0;
  for (int i = 1; i <= n; i++)
    tim += max(0ll, (1ll * m * a[i] + h[i] - lim + p - 1) / p);
  if (tim > m * K) return false;
  for (int i = 1; i <= n; i++) {
    long long ht = 1ll * m * a[i] + h[i];
    if (ht <= lim) continue;
    for (long long tmp = (ht - lim - 1) % p + 1; tmp <= ht - lim; tmp += p) {
      if (tmp <= h[i])
        t[0]++;
      else if (tmp > h[i] + 1ll * (m - 1) * a[i])
        return 0;
      else
        t[(tmp - h[i] + a[i] - 1) / a[i]]++;
    }
  }
  int res = 0;
  for (int i = 0; i < m; i++) {
    res += t[i], t[i] = 0;
    res = max(0, res - K);
  }
  if (res) return false;
  return true;
}
int main() {
  n = read(), m = read(), K = read(), p = read();
  for (int i = 1; i <= n; i++) h[i] = read(), a[i] = read();
  long long l = 0, r = 5e12 + 1e9, res = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << res << '\n';
}
