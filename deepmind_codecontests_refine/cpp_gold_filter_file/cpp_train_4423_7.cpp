#include <bits/stdc++.h>
namespace imzzy {
class fastin {
 private:
  int _ch, _f;

 public:
  inline fastin &operator>>(char &c) {
    c = getchar();
    return *this;
  }
  template <typename _Tp>
  inline fastin &operator>>(_Tp &_x) {
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
const int maxn = 1004, maxm = 500004;
int nxt[maxn], pre[maxn], p[5];
bool g1[maxn][maxn], g2[maxn][maxn];
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > ans1, ans2;
inline std::pair<std::pair<int, int>, std::pair<int, int> > rev(
    int u, int v, int n, bool g[maxn][maxn]) {
  int indx = 0;
  for (register int i = 1; i <= n; ++i)
    if (g[u][i] && g[v][i]) p[++indx] = i;
  g[u][v] = g[v][u] = 0, g[p[1]][p[2]] = g[p[2]][p[1]] = 1;
  return std::make_pair(std::make_pair(u, v), std::make_pair(p[1], p[2]));
}
inline void work(
    int n, bool g[maxn][maxn],
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > &res) {
  for (register int i = 2; i <= n; ++i) {
    for (register int j = n; j > 1; --j) {
      if (j == i || j == pre[i] || j == nxt[i]) continue;
      if (g[i][j]) res.push_back(rev(i, j, n, g));
    }
  }
}
signed main() {
  int n, u, v;
  fin >> n;
  for (register int i = 1; i <= n; ++i) pre[i] = i - 1, nxt[i] = i + 1;
  pre[1] = n, nxt[n] = 1;
  for (register int i = 1; i <= n; ++i)
    g1[i][pre[i]] = g1[i][nxt[i]] = g2[i][pre[i]] = g2[i][nxt[i]] = 1;
  for (register int i = 1; i <= n - 3; ++i)
    fin >> u >> v, g1[u][v] = g1[v][u] = 1;
  for (register int i = 1; i <= n - 3; ++i)
    fin >> u >> v, g2[u][v] = g2[v][u] = 1;
  work(n, g1, ans1), work(n, g2, ans2);
  std::cout << ans1.size() + ans2.size() << '\n';
  for (register int i = 0; i < ans1.size(); ++i)
    std::cout << ans1[i].first.first << ' ' << ans1[i].first.second << '\n';
  for (register int i = ans2.size() - 1; i >= 0; --i)
    std::cout << ans2[i].second.first << ' ' << ans2[i].second.second << '\n';
  return 0;
}
