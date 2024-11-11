#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 7;
namespace FastIO {
template <typename tp>
inline void read(tp &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
template <typename tp>
inline void write(tp x) {
  if (x == 0) return (void)(putchar('0'));
  if (x < 0) putchar('-'), x = -x;
  long long pr[20];
  register long long cnt = 0;
  for (; x; x /= 10) pr[++cnt] = x % 10;
  while (cnt) putchar(pr[cnt--] + '0');
}
template <typename tp>
inline void writeln(tp x) {
  write(x);
  putchar('\n');
}
}  // namespace FastIO
using namespace FastIO;
int n, l, r;
int a[N], b[N], zz;
int xiao(int x) {
  int ret = inf;
  for (int i = x; i > x - 5; i--) ret = min(ret, a[i]);
  return ret;
}
int da(int x) {
  int ret = -inf;
  for (int i = x; i > x - 5; i--) ret = max(ret, a[i]);
  return ret;
}
string s;
int main() {
  read(n);
  l = -inf, r = inf;
  for (int i = 1; i <= n; i++) read(a[i]);
  cin >> s;
  for (int i = 0; i < n; i++) b[i + 1] = s[i] - 48;
  for (int i = 5; i <= n; i++) {
    if (b[i] != b[i - 1]) {
      if (b[i] == 1)
        l = max(l, da(i) + 1);
      else
        r = min(r, xiao(i) - 1);
    }
  }
  printf("%d ", l), writeln(r);
  return 0;
}
