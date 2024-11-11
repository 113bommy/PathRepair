#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
pair<vector<int>, set<int> > comp[N];
vector<map<int, int> > g;
int at[N];
int compSize(int u) { return comp[u].first.size() + comp[u].second.size(); }
void merge(int a, int b) {
  a = at[a];
  b = at[b];
  if (a == b) return;
  if (compSize(a) > compSize(b)) swap(a, b);
  for (auto &x : comp[a].first) {
    at[x] = b;
    comp[b].first.push_back(x);
  }
  comp[b].second.insert(comp[a].second.begin(), comp[a].second.end());
}
void addEdge(int a, int b, int c) {
  comp[at[a]].second.insert(b);
  comp[at[b]].second.insert(a);
  for (int q = 0; q < 2; ++q) {
    auto it = g[a].find(c);
    if (it != g[a].end())
      merge(at[it->second], at[b]);
    else
      g[a][c] = b;
    swap(a, b);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  g.resize(n);
  for (int i = 0; i < n; ++i) {
    at[i] = i;
    comp[i].first.push_back(i);
  }
  int m, c, q;
  scanf("%d%d%d", &m, &c, &q);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    --a;
    --b;
    addEdge(a, b, c);
  }
  char t;
  while (q--) {
    int u, v, c;
    scanf(" %c%d%d", &t, &u, &v);
    --u;
    --v;
    if (t == '+') {
      scanf("%d", &c);
      addEdge(u, v, c);
    } else {
      if (u == v || comp[at[u]].second.count(v))
        puts("Yes");
      else
        puts("No");
    }
  }
  return 0;
}
