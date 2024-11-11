#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <int n, class... T>
typename std::enable_if<(n >= sizeof...(T))>::type __output_tuple(
    std::ostream &, std::tuple<T...> const &) {}
template <int n, class... T>
typename std::enable_if<(n < sizeof...(T))>::type __output_tuple(
    std::ostream &os, std::tuple<T...> const &t) {
  os << (n == 0 ? "" : ", ") << std::get<n>(t);
  __output_tuple<n + 1>(os, t);
}
template <class... T>
std::ostream &operator<<(std::ostream &os, std::tuple<T...> const &t) {
  os << "(";
  __output_tuple<0>(os, t);
  os << ")";
  return os;
}
template <class T, class U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> const &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const std::stack<T> &a) {
  os << "{";
  for (auto tmp = a; tmp.size(); tmp.pop())
    os << (a.size() == tmp.size() ? "" : ", ") << tmp.top();
  os << "}";
  return os;
}
template <class T, class Container, class Compare>
std::ostream &operator<<(std::ostream &os,
                         std::priority_queue<T, Container, Compare> a) {
  os << "{ (top) ";
  while (a.size()) os << a.top() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template <class T, class Container>
std::ostream &operator<<(std::ostream &os, std::queue<T, Container> a) {
  os << "{ ";
  while (a.size()) os << a.front() << (a.size() == 1 ? "" : ", "), a.pop();
  os << " }";
  return os;
}
template <
    class T,
    class = typename std::iterator_traits<decltype(begin(T()))>::value_type,
    class = typename std::enable_if<!std::is_same<T, std::string>::value>::type>
std::ostream &operator<<(std::ostream &os, const T &a) {
  for (auto ite = begin(a); ite != end(a); ++ite)
    os << (ite == begin(a) ? "" : " ") << *ite;
  return os;
}
int dp[1 << 12][12][12];
int dp2[1 << 12][12];
int n, m;
int idx[12];
int a[12][2000];
int h;
int modn[200];
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> used(m);
    vector<pair<int, int>> g;
    for (int i = 0; i < 200; i++) modn[i] = i % n;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) cin >> a[i][j], g.emplace_back(a[i][j], j);
    sort(begin(g), end(g));
    h = 0;
    while (g.size() && h < n) {
      int i;
      tie(ignore, i) = g.back();
      g.pop_back();
      if (!used[i]) {
        ((void)42);
        used[i] = 1;
        idx[h] = i;
        h++;
      }
    }
    for (int x = 0; x < 1 << n; x++)
      for (int k = h - 1; k >= 0; k--) {
        for (int l = 0; l < n; l++) {
          dp[x][k][l] = 0;
          int res = k + 1 < h ? dp2[t][k + 1] : 0;
          for (int i = 0; i < n; i++)
            if ((1 << i) & x) {
              int f = a[modn[i + l]][idx[k]];
              int g = 0;
              g = dp[(1 << i) ^ x][k][l];
              if (k + 1 < h) g = max(g, dp2[(1 << i) ^ x][k + 1]);
              res = max(res, g + f);
            }
          dp[x][k][l] = res;
        }
        dp2[x][k] = 0;
        for (int z = 0; z < n; z++) dp2[x][k] = max(dp2[x][k], dp[x][k][z]);
      }
    int ans = dp2[(1 << n) - 1][0];
    cout << ans << "\n";
  }
  return 0;
}
