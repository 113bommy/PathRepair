#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1000000007;
bool shrink_tree(int v, int p, vector<vector<int> >& g, set<int> const& vs) {
  bool can_drop = not vs.count(v);
  vector<int> es;
  for (int w : g[v])
    if (w != p) {
      if (shrink_tree(w, v, g, vs)) {
      } else {
        es.push_back(w);
        can_drop = false;
      }
    }
  if (not can_drop and p != inf) es.push_back(p);
  g[v].swap(es);
  return can_drop;
}
int size(int v, int p, vector<vector<int> >& g) {
  int result = 1;
  for (int w : g[v])
    if (w != p) {
      result += size(w, v, g);
    }
  return result;
}
pair<int, int> farthest(int v, int p, vector<vector<int> >& g) {
  auto result = make_pair(0, -v);
  for (int w : g[v])
    if (w != p) {
      result = max(result, farthest(w, v, g));
    }
  result.first += 1;
  return result;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > g(n);
  for (int i = (0); (i) < (n - 1); ++(i)) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  set<int> vs;
  for (int i = (0); (i) < (m); ++(i)) {
    int v;
    cin >> v;
    --v;
    vs.insert(v);
  }
  int v0 = *vs.begin();
  shrink_tree(v0, inf, g, vs);
  int sz = size(v0, inf, g);
  int v1 = -farthest(v0, inf, g).second;
  int v2, diameter;
  tie(diameter, v2) = farthest(v1, inf, g);
  v2 *= -1;
  int v3 = -farthest(v2, inf, g).second;
  cout << v2 + 1 << endl;
  cout << 2 * sz - diameter - 1 << endl;
  return 0;
}
