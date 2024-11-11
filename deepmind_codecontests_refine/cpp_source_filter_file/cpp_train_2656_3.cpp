#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
template <typename t>
using V = vector<t>;
template <typename t, size_t s>
using A = array<t, s>;
void print() { cout << '\n'; }
template <typename t, typename... v>
void print(const t& a, const v&... b) {
  cout << a << (sizeof...(b) ? " " : "");
  print(b...);
}
template <typename t>
void print_range(t a, const t& b) {
  while (a != b) cout << (*a++) << ' ';
  cout << '\n';
}
constexpr int nax = 1e5, maxm = nax;
struct Edge {
  int first, second, id;
};
inline bool operator<(const Edge& mn, const Edge& wc) {
  return make_pair(mn.first, mn.second) < make_pair(wc.first, wc.second);
}
int n, m, p = 1, x, y;
Edge eds[maxm];
pair<int, int> res[maxm];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 0; i < m; ++i)
    cin >> eds[i].first >> eds[i].second, eds[i].second = -eds[i].second,
                                          eds[i].id = i;
  sort(begin(eds), begin(eds) + m);
  for (int i = 0; i < m; ++i) eds[i].second = -eds[i].second;
  for (int i = 0; i < m; ++i) {
    if (eds[i].second) {
      if (p == n) return print(-1), 0;
      ++p;
      res[eds[i].id] = {p - 1, p};
    }
    if (not eds[i].second) {
      while (not y) ++x, y = x - 1;
      if (x > p) return print(-1), 0;
      res[eds[i].id] = {x, y--};
    }
  }
  for (int i = 0; i < m; ++i) print(res[i].first, res[i].second);
}
