#include <bits/stdc++.h>
namespace chtholly {
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar()) f ^= c == '-';
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return f ? x : -x;
}
template <typename mitsuha>
inline bool read(mitsuha &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  for (; !isdigit(c) && ~c; c = getchar()) f ^= c == '-';
  if (!~c) return 0;
  for (; isdigit(c); c = getchar()) x = (x << 3) + (x << 1) + (c ^ '0');
  return x = f ? x : -x, 1;
}
template <typename mitsuha>
inline int write(mitsuha x) {
  if (!x) return 0 & putchar(48);
  if (x < 0) x = -x, putchar('-');
  int bit[20], i, p = 0;
  for (; x; x /= 10) bit[++p] = x % 10;
  for (i = p; i; --i) putchar(bit[i] + 48);
  return 0;
}
inline char fuhao() {
  char c = getchar();
  for (; isspace(c); c = getchar())
    ;
  return c;
}
}  // namespace chtholly
using namespace chtholly;
using namespace std;
long long a, b, c, l;
long long get(long long a, long long b, long long c) {
  long long llx = 0, i, t;
  for (i = max(b + c - a, 0ll); i <= l; ++i) {
    t = min(a + i - b - c, l - i);
    llx += (t + 1) * (t + 2) >> 1;
  }
  return llx;
}
int main() {
  long long ans = 0, l1, l2, l3;
  cin >> a >> b >> c >> l;
  for (l1 = 0; l1 <= l; ++l1) ans += (l1 + 1) * (l1 + 2) >> 1;
  write(ans - get(a, b, c) - get(b, c, a) - get(c, a, b));
}
