#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 28;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
long long n;
long long sumup(long long x) { return 3 * x * (x + 1); }
int main() {
  cin >> n;
  long long l = 0, r = 1000000000;
  while (l <= r) {
    long long m = l + r >> 1;
    if (n <= sumup(m))
      r = m - 1;
    else
      l = m + 1;
  }
  n -= sumup(l - 1);
  if (n <= l) {
    cout << 2 * l - n << " " << 2 * n << endl;
  } else if (l < n && n <= 2 * l) {
    n -= l;
    cout << l - 2 * n << " " << 2 * l << endl;
  } else if (2 * l < n && n <= 3 * l) {
    n -= 2 * l;
    cout << -l - n << " " << 2 * l - 2 * n << endl;
  } else if (3 * l < n && n <= 4 * l) {
    n -= 3 * l;
    cout << n - 2 * l << " " << -2 * n << endl;
  } else if (4 * l < n && n <= 5 * l) {
    n -= 4 * l;
    cout << 2 * n - l << " " << -2 * l << endl;
  } else {
    n -= 5 * l;
    cout << l + n << " " << 2 * n - 2 * l << endl;
  }
  return 0;
}
