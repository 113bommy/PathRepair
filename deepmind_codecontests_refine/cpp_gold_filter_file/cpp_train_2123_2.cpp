#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pii = pair<int, int>;
char el = '\n';
ostream &operator<<(ostream &os, const vector<int> &v) {
  for (auto const &i : v) {
    os << i << " ";
  }
  os << endl;
  return os;
}
const int N = 1e5 + 5;
vector<vector<int>> g(N);
bitset<N> visited;
unordered_map<int, int> m;
vi fst;
vi ans;
void dfs(int v) {
  visited[v] = 1;
  for (int u : g[v]) {
    if (!visited[u]) dfs(u);
  }
  fst.push_back(v);
}
void dfs2(int v) {
  visited[v] = 1;
  ans.push_back(v);
  for (int u : g[v]) {
    if (!visited[u]) dfs2(u);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  vector<pii> v(n);
  vi ns;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    ns.push_back(v[i].first);
    ns.push_back(v[i].second);
  }
  sort(ns.begin(), ns.end());
  ns.erase(unique(ns.begin(), ns.end()), ns.end());
  int u = 0;
  for (auto &x : ns) {
    m[x] = u;
    u++;
  }
  for (auto &x : v) {
    g[m[x.first]].push_back(m[x.second]);
    g[m[x.second]].push_back(m[x.first]);
  }
  dfs(0);
  visited.reset();
  dfs2(fst[0]);
  for (auto x : ans) {
    cout << ns[x] << " ";
  }
}
