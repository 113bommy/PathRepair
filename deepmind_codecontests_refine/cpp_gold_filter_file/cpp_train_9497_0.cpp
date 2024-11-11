#include <bits/stdc++.h>
using namespace std;
vector<set<long long int>> g;
set<long long int> leaf;
long long int ask(long long int u, long long int v) {
  cout << "? " << u + 1 << ' ' << v + 1 << endl;
  long long int x;
  cin >> x;
  return x - 1;
}
void answer(long long int r) {
  cout << "! " << r + 1 << endl;
  exit(0);
}
void deleteFromGraph(long long int x, long long int last,
                     long long int blockpoint) {
  if (leaf.find(x) != leaf.end()) leaf.erase(x);
  for (auto u : g[x]) {
    if (u == last) continue;
    if (u == blockpoint)
      g[u].erase(x);
    else if (g[u].size() != 0)
      deleteFromGraph(u, x, blockpoint);
  }
  g[x].clear();
}
void solve() {
  long long int n;
  cin >> n;
  g.resize(n);
  for (long long int i = 1; i < n; ++i) {
    long long int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].insert(y);
    g[y].insert(x);
  }
  for (long long int i = 0; i < n; ++i) {
    if (g[i].size() == 1) leaf.insert(i);
  }
  while (leaf.size() > 1) {
    long long int u = *leaf.begin();
    leaf.erase(u);
    long long int v = *leaf.begin();
    leaf.erase(v);
    long long int w = ask(u, v);
    if (w == u or w == v) answer(w);
    deleteFromGraph(u, -1, w);
    deleteFromGraph(v, -1, w);
    if (g[w].size() <= 1) leaf.insert(w);
  }
  answer(*leaf.begin());
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
