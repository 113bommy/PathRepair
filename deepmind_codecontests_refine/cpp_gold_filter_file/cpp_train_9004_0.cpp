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
const long long mod = 51123987, inf = 1201201201, debug = 0;
const int maxn = 1000004, maxm = 204;
std::pair<int, int> p[maxn];
std::set<int> s;
signed main() {
  int n;
  fin >> n;
  for (register int i = 1; i <= n; ++i) fin >> p[i].first, p[i].second = i;
  std::sort(p + 1, p + 1 + n, std::greater<std::pair<int, int> >());
  s.insert(0), s.insert(n + 1);
  long long ans = 0, tmp, cnt;
  for (register int i = 1, j; i <= n;) {
    for (j = i + 1; p[i].first == p[j].first; ++j)
      ;
    tmp = cnt = 0;
    ans += (j - i) * std::min(2, int(s.size()) - 2);
    for (register int k = i; k < j; ++k) {
      std::set<int>::iterator it = s.upper_bound(p[k].second), ti;
      ti = it, --it;
      if (*ti == n + 1) {
        ++tmp;
        continue;
      }
      if (*it == 0) {
        ++tmp;
        continue;
      }
      if (p[k - 1].second > *ti)
        ans += cnt * (cnt - 1) / 2, cnt = 1;
      else
        ++cnt;
    }
    for (register int k = i; k < j; ++k) s.insert(p[k].second);
    ans += tmp * (tmp - 1) / 2 + cnt * (cnt - 1) / 2;
    i = j;
  }
  std::cout << ans;
  return 0;
}
