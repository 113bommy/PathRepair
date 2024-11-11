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
int n, vis[N], Ans, Mx;
int main() {
  register int i, x;
  read(n);
  for (i = 1; i <= n; i++) {
    char op;
    cin >> op;
    read(x);
    if (op == '+') {
      vis[x] = 1;
      Ans++;
    } else {
      if (vis[x])
        vis[x] = 0, Ans--;
      else
        Mx++, Ans--;
    }
    Mx = ((Mx) > (Ans) ? (Mx) : (Ans));
  }
  return writeln(Mx), 0;
}
