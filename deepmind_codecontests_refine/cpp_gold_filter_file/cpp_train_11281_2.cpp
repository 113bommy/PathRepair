#include <bits/stdc++.h>
namespace imzzy {
class fastin {
 private:
  int _ch, _f;

 public:
  inline fastin& operator>>(char& c) {
    c = getchar();
    return *this;
  }
  template <typename _Tp>
  inline fastin& operator>>(_Tp& _x) {
    _x = 0;
    while (!isdigit(_ch)) _f |= (_ch == 45), _ch = getchar();
    while (isdigit(_ch))
      _x = (_x << 1) + (_x << 3) + (_ch ^ 48), _ch = getchar();
    _f && (_x = -_x, _f = 0);
    return *this;
  }
  fastin() { _ch = _f = 0; }
} fin;
}  // namespace imzzy
using namespace imzzy;
const long long mod = 51123987, inf = 1000000007ll, debug = 0;
const int maxn = 200004, maxm = 1000004;
struct Fruit {
  int a, o, num;
} h[maxn];
inline bool cmp(Fruit x, Fruit y) { return x.a < y.a; }
int ans[maxn], indx;
signed main() {
  int t, n;
  fin >> t;
  while (t--) {
    fin >> n;
    for (register int i = 1; i <= n * 2 - 1; ++i)
      fin >> h[i].a >> h[i].o, h[i].num = i;
    std::sort(h + 1, h + n * 2, cmp), indx = 0;
    for (register int i = 1; i < n * 2 - 1; i += 2) {
      if (h[i + 1].o > h[i].o)
        ans[++indx] = h[i + 1].num;
      else
        ans[++indx] = h[i].num;
    }
    ans[++indx] = h[2 * n - 1].num;
    std::sort(ans + 1, ans + 1 + n);
    puts("YES");
    for (register int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
    std::cout << '\n';
  }
  return 0;
}
