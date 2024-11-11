#include <bits/stdc++.h>
using namespace std;
namespace io {
const int l = 1 << 20;
char buf[l], *s, *t;
inline char gc() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, l, stdin);
    return s == t ? EOF : *s++;
  }
  return *s++;
}
char c;
template <class IT>
inline void gi(IT &x) {
  x = 0;
  c = gc();
  while (c < '0' || c > '9') c = gc();
  while ('0' <= c && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ '0');
    c = gc();
  }
}
};  // namespace io
using io::gi;
template <class IT>
inline void cmin(IT &a, IT b) {
  if (b < a) a = b;
}
template <class IT>
inline void cmax(IT &a, IT b) {
  if (a < b) a = b;
}
const long long p = 998244353ll;
const int N = 200005;
int main() {
  int a, b, n, s = 0, i, j, k, l, r, l1, r1, l2, r2;
  scanf("%d%d", &a, &b);
  n = a + b;
  for (i = 1, j; i <= n; i = j + 1) {
    j = n / (k = n / i);
    if (a < k || b < k) continue;
    l1 = (a + k) / (k + 1);
    r1 = a / k;
    l2 = (b + k) / (k + 1);
    r2 = b / k;
    if (r1 < l2 || r2 < l2) continue;
    l = max(i, l1 + l2);
    r = min(j, r1 + r2);
    if (l <= r) s += r - l + 1;
  }
  printf("%d", s);
  return 0;
}
