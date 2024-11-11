#include <bits/stdc++.h>
using namespace std;
namespace Debug {
template <typename Ty>
inline void _debug(const char* f, Ty t) {
  cerr << f << '=' << t << endl;
}
template <typename Ty, typename... Ar>
inline void _debug(const char* f, Ty x, Ar... y) {
  while (*f != ',') cerr << *f++;
  cerr << '=' << x << ",";
  _debug(f + 1, y...);
}
template <typename Ty>
ostream& operator<<(ostream& os, const vector<Ty>& V) {
  os << "[";
  for (const auto& vv : V) os << vv << ",";
  os << "]";
  return os;
}
}  // namespace Debug
using namespace Debug;
namespace FastIO {
template <typename Ty>
inline void read(Ty& x) {
  char c;
  int f = 1;
  x = 0;
  while (!isdigit(c = getchar())) f = c ^ '-' ? 1 : -1;
  while (x = (x << 3) + (x << 1) + (c & 15), isdigit(c = getchar()))
    ;
  x *= f;
}
template <typename Ty, typename... Ar>
inline void read(Ty& x, Ar&... y) {
  read(x), read(y...);
}
template <typename Ty>
inline void write(Ty x) {
  x < 0 && (putchar(('-')), x = -x, 0),
      x < 10 ? (putchar((x + '0')), 0)
             : (write(x / 10), putchar((x % 10 + '0')), 0);
}
template <typename Ty>
inline void writeln(const Ty& x) {
  write(x), putchar(('\n'));
}
}  // namespace FastIO
using namespace FastIO;
const int N = 1e6 + 10;
int n, k, a[N], cnt[N], c0, c1;
long long s0, s1, Ans;
int main() {
  register int i;
  for (read(n), i = 1; i <= n; i++)
    read(a[i]), a[i] > i ? ++cnt[a[i] - i], ++c0,
        s0 += a[i] - i : (++c1, s1 += i - a[i]);
  Ans = s0 + s1;
  for (i = 1; i <= n; i++)
    s0 -= c0, s1 += c1, c0 -= cnt[i], c1 += cnt[i],
        (--c1, s1 -= (n + 1) - a[n - i + 1]),
        a[n - i + 1] > 1       ? ++cnt[a[n - i + 1] - 1 + i], ++c0,
        s0 += a[n - i + 1] - 1 : ++c1, s0 + s1 < Ans && (Ans = s0 + s1, k = i);
  return write(Ans), putchar((' ')), writeln(k), 0;
}
