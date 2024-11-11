#include <bits/stdc++.h>
namespace cplib {
using namespace std;
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read_n(InputIt it, int n) {
  copy_n(istream_iterator<T>(cin), n, it);
}
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void read(InputIt first, InputIt last) {
  read_n(first, distance(first, last));
}
template <typename InputIt,
          typename T = typename iterator_traits<InputIt>::value_type>
void write(InputIt first, InputIt last, const char *delim = "\n") {
  copy(first, last, ostream_iterator<T>(cout, delim));
}
}  // namespace cplib
using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int main(void) {
  ios::sync_with_stdio(false), cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b, a--, b--;
    vector<vi> g(n);
    while (m--) {
      int u, v;
      cin >> u >> v, u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<bool> vis(n, false);
    function<int(int, int)> dfs = [&](int u, int exc) {
      int cnt = 1;
      vis[u] = true;
      for (auto v : g[u])
        if (!vis[v] and v != exc) cnt += dfs(v, exc);
      return cnt;
    };
    int x = dfs(a, b);
    fill(begin(vis), end(vis), false);
    int y = dfs(b, a);
    cout << (n - x - 1) * (n - y - 1) << endl;
  }
  return 0;
}
