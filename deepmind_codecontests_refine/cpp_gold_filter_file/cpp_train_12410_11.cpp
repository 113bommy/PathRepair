#include <bits/stdc++.h>
using namespace std;
namespace fast {
inline char nc() {
  static char buf[100000], *L = buf, *R = buf;
  return L == R && (R = (L = buf) + fread(buf, 1, 100000, stdin), L == R)
             ? EOF
             : *L++;
}
template <class orz>
inline void qread(orz& x) {
  x = 0;
  char ch = nc();
  bool f = 0;
  while (ch < '0' || ch > '9') (ch == '-') && (f = 1), ch = nc();
  while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = nc();
  f && (x = -x);
}
}  // namespace fast
using namespace fast;
template <class orz>
inline void read(orz& x) {
  x = 0;
  bool f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') (ch == '-') && (f = 1), ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  f && (x = -x);
}
template <class orz>
inline void out(orz x) {
  (x < 0) && (putchar('-'), x = -x);
  if (x > 9) out(x / 10);
  putchar(x % 10 + '0');
}
const double PI = acos(-1);
const double eps = 1e-8;
const long long mod = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
int n, a[maxn], b[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k1, k2, amax, bmax;
    amax = bmax = -INF;
    cin >> n >> k1 >> k2;
    for (int i = 0; i < k1; i++) {
      read(a[i]);
      amax = max(amax, a[i]);
    }
    for (int i = 0; i < k2; i++) {
      read(b[i]);
      bmax = max(bmax, b[i]);
    }
    if (amax > bmax)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
