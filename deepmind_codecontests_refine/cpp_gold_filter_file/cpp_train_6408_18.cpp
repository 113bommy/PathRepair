#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, a[200010], Ans = 0x3fffffff, mid;
inline bool calc(int gs, int cur, int st) {
  for (int i = st; i < n; i++) {
    if (cur >= a[i])
      cur = a[i] + mid + 1;
    else {
      if (a[i] > cur + mid)
        return 0;
      else if (i < n - 1 && a[i + 1] != a[i] + 1 && a[i + 1] <= cur + mid)
        cur = a[i++] + mid + 1;
      else
        cur = a[i] + 1;
    }
  }
  return cur + gs >= a[n];
}
inline bool well(int x) {
  if (a[0] + 2 * x + 1 < a[1]) return 0;
  if (calc(0, a[0] + x + 1, 1)) return 1;
  if (a[0] + x > a[1] && calc(x - a[1] + a[0], a[0] + x + 1, 2)) return 1;
  return 0;
}
inline void check() {
  int l = 0, r = m, ret = 0x3fffffff;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (well(mid))
      r = mid - 1, ret = mid;
    else
      l = mid + 1;
  }
  Ans = min(Ans, ret);
}
int main() {
  m = read();
  n = read();
  for (int i = 0; i < n; i++) a[i] = read();
  a[n] = a[0] + m;
  check();
  reverse(a, a + 1 + n);
  for (int i = 0; i <= n; i++) a[i] = -a[i];
  check();
  cout << Ans << endl;
  return 0;
}
