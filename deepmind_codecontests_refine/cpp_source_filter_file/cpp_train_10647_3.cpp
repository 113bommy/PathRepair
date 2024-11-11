#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  ~debug() { cerr << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cerr << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
};
int n, m;
vector<int> adj[1000001];
vector<int> visited(100011);
map<int, int> is;
vector<int> top_order;
bool possible;
void dfs(int v) {
  visited[v] = 1;
  for (int u : adj[v]) {
    if (!visited[u])
      dfs(u);
    else if (visited[u] == 1)
      possible = 1;
  }
  visited[v] = 2;
  top_order.push_back(v);
}
bool topological_sort() {
  int n = 25;
  visited.assign(n + 1, 0);
  top_order.clear();
  for (int i = 0; i < n; ++i) {
    if (visited[i] == 0 && is[i]) dfs(i);
  }
  reverse(top_order.begin(), top_order.end());
  if (possible == 1) return false;
  return true;
}
void solve() {
  vector<string> v;
  cin >> n >> m;
  vector<vector<string>> ss(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int j = 0; j < m; j++) {
      string sa;
      cin >> sa;
      for (auto it : sa) is[it - 'a'] = 1;
      ss[a].push_back(sa);
    }
  }
  for (int i = 0; i < n; i++) {
    for (auto it : ss[i]) v.push_back(it);
  }
  for (int i = 0; i < (n * m) - 1; i++) {
    if (v[i].length() >= v[i + 1].length()) {
      bool f = 0;
      for (int j = 0; j < v[i + 1].length(); j++) {
        if (v[i][j] != v[i + 1][j]) {
          adj[v[i][j] - 'a'].push_back(v[i + 1][j] - 'a');
          f = 1;
          goto end1;
        }
      }
    end1:;
      if (f == 0) {
        cout << "IMPOSSIBLE" << endl;
        return;
      }
    } else {
      for (int j = 0; j < v[i].length(); j++) {
        if (v[i][j] != v[i + 1][j]) {
          adj[v[i][j] - 'a'].push_back(v[i + 1][j] - 'a');
          break;
        }
      }
    }
  end:;
  }
  bool ok = topological_sort();
  if (!ok) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  map<int, int> done;
  for (auto it : top_order) done[it] = 1;
  for (int i = 0; i < 26; i++) {
    if (is[i] && done[i] == 0) cout << char(i + 'a');
  }
  for (auto it : top_order) {
    done[it] = 1;
    cout << char('a' + it);
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) solve();
  return 0;
}
