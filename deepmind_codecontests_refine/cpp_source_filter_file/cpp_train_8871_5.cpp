#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> used;
vector<int> d, p, at_cycle;
int cycle_start, cycle_end;
bool find_cycle(int v) {
  used[v] = true;
  for (vector<int>::iterator to = g[v].begin(); to != g[v].end(); ++to) {
    if (!used[*to]) {
      p[*to] = v;
      if (find_cycle(*to)) return true;
    } else if (p[v] != *to) {
      cycle_start = *to;
      cycle_end = v;
      return true;
    }
  }
  return false;
}
void dfs(int v, int sz) {
  used[v] = true;
  d[v] = sz;
  for (vector<int>::iterator to = g[v].begin(); to != g[v].end(); ++to) {
    if (!used[*to]) dfs(*to, sz + 1);
  }
}
int main() {
  int n;
  cin >> n;
  g.resize(n);
  used.resize(n);
  p.resize(n);
  d.resize(n);
  for (int i = 0; i < n; ++i) {
    int v, to;
    cin >> v >> to;
    v--, to--;
    g[v].push_back(to);
    g[to].push_back(v);
  }
  find_cycle(1);
  for (int v = cycle_end; v != cycle_start; v = p[v]) at_cycle.push_back(v);
  at_cycle.push_back(cycle_start);
  used.clear();
  used.resize(n);
  for (vector<int>::iterator v = at_cycle.begin(); v != at_cycle.end(); ++v)
    used[*v] = true;
  for (vector<int>::iterator v = at_cycle.begin(); v != at_cycle.begin(); ++v) {
    dfs(*v, 0);
  }
  for (vector<int>::iterator sz = d.begin(); sz != d.end(); ++sz)
    cout << *sz << " ";
  return 0;
}
