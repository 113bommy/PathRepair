#include <bits/stdc++.h>
using std::abs;
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::generate;
using std::make_pair;
using std::map;
using std::max;
using std::max_element;
using std::min;
using std::min_element;
using std::pair;
using std::reverse;
using std::set;
using std::sort;
using std::string;
using std::unique;
using std::vector;
template <typename T>
T input() {
  T res;
  cin >> res;
  {};
  return res;
}
template <typename IT>
void input_seq(IT b, IT e) {
  std::generate(b, e,
                input<typename std::remove_reference<decltype(*b)>::type>);
}
void dfs(const vector<vector<int>>& graph, vector<int>& par, vector<char>& mark,
         vector<int>& blad, int v, int p) {
  par[v] = p;
  mark[v] = 1;
  for (int u : graph[v])
    if (mark[u] == 0) {
      dfs(graph, par, mark, blad, u, v);
    } else if (u != p and mark[u] == 1) {
      int lo = u;
      int hi = u;
      for (int i = v; i != u; i = par[i]) {
        lo = min(lo, i);
        hi = max(hi, i);
      }
      blad[lo] = min(blad[lo], hi);
    }
  mark[v] = 2;
}
vector<int> tree[4 * (300 * 1000)];
vector<int> sums[4 * (300 * 1000)];
void build_blad(int no, int nl, int nr, vector<int>& blad) {
  tree[no].resize(nr - nl);
  if (nr - nl == 1)
    tree[no][0] = blad[nl];
  else {
    int mi = nl + (nr - nl) / 2;
    build_blad(2 * no + 1, nl, mi, blad);
    build_blad(2 * no + 2, mi, nr, blad);
    std::merge(tree[2 * no + 1].begin(), tree[2 * no + 1].end(),
               tree[2 * no + 2].begin(), tree[2 * no + 2].end(),
               tree[no].begin());
  }
  sums[no].resize(nr - nl + 1);
  for (int i = 0; i != nr - nl; ++i)
    sums[no][i + 1] = sums[no][i] + tree[no][i];
}
int64_t req(int no, int nl, int nr, int l, int r, int lim) {
  if (nr <= l or r <= nl) return 0;
  if (l <= nl and nr <= r) {
    int ptr = std::upper_bound(tree[no].begin(), tree[no].end(), lim) -
              tree[no].begin();
    return (nr - nl - ptr) * int64_t(lim) + sums[no][ptr];
  }
  int mi = nl + (nr - nl) / 2;
  return req(2 * no + 1, nl, mi, l, r, lim) +
         req(2 * no + 2, mi, nr, l, r, lim);
}
int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n = input<int>();
  int m = input<int>();
  vector<vector<int>> graph(n);
  for (int i = 0; i != m; ++i) {
    int v = input<int>() - 1;
    int u = input<int>() - 1;
    graph[v].push_back(u);
    graph[u].push_back(v);
  }
  vector<int> par(n, -1);
  vector<char> mark(n, 0);
  vector<int> blad(n, std::numeric_limits<int>::max());
  for (int i = 0; i != n; ++i)
    if (mark[i] == 0) dfs(graph, par, mark, blad, i, -1);
  for (int i = n - 2; i >= 0; --i) blad[i] = min(blad[i], blad[i + 1]);
  for (int i = 0; i != n; ++i) --blad[i];
  build_blad(0, 0, n, blad);
  for (int q = input<int>(); q != 0; --q) {
    int v = input<int>() - 1;
    int u = input<int>() - 1;
    int64_t ans = (u - v + 1) - (u - v + 1) * int64_t(u + v) / 2;
    ans += req(0, 0, n, v, u + 1, u);
    cout << ans << "\n";
  }
  return 0;
}
