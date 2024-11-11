#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = 1e18 + 10;
const int MAX = 1e5 + 10;
int n, m, h, ng;
int a[MAX];
vector<int> es[MAX];
vector<int> group[MAX];
int mark[MAX];
stack<int> ord;
bool oute;
void visit(int u) {
  mark[u] = 1;
  for (auto v : es[u])
    if (!mark[v] && (a[u] + 1) % h == a[v]) visit(v);
  ord.push(u);
}
void rev_visit(int u) {
  mark[u] = ng;
  group[ng].push_back(u);
  for (auto v : es[u])
    if (!mark[v] && (a[v] + 1) % h == a[u]) rev_visit(v);
}
bool check(int id) {
  for (auto u : group[id]) {
    for (auto v : es[u])
      if (mark[u] != mark[v] && (a[u] + 1) % h == a[v]) return false;
  }
  return true;
}
void process() {
  cin >> n >> m >> h;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    es[u].push_back(v);
    es[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!mark[i]) visit(i);
  memset(mark, 0, sizeof(mark));
  int res = INF, rp = 0;
  while (!ord.empty()) {
    int u = ord.top();
    ord.pop();
    if (mark[u]) continue;
    ng++;
    rev_visit(u);
    if (check(ng) && int(group[ng].size()) < res) {
      res = int(group[ng].size());
      rp = ng;
    }
  }
  cout << int(group[rp].size()) << '\n';
  for (auto x : group[rp]) cout << x << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
