#include <bits/stdc++.h>
using namespace std;
template <typename T>
using vc = vector<T>;
using pii = pair<long long, long long>;
void xmax(long long& a, long long b) { a = max(a, b); }
void xmin(long long& a, long long b) { a = min(a, b); }
void print(vc<long long>& a, string second) {
  cerr << "prinitng " << second << "\n";
  for (long long i = 0; i < a.size(); i++) {
    cerr << a[i] << " ";
  }
  cerr << endl;
}
struct scc {
  vector<vector<long long> > g, g_rev;
  vector<bool> visited;
  vector<long long> group_num;
  long long group_cnt;
  stack<long long> second;
  scc(size_t n) : g(n), g_rev(n), visited(n), group_num(n), group_cnt(0) {}
  void add_edge(long long a, long long b) {
    g[a].push_back(b);
    g_rev[b].push_back(a);
  }
  void fill_forward(long long v) {
    visited[v] = true;
    for (long long w : g[v])
      if (!visited[w]) fill_forward(w);
    second.push(v);
  }
  void fill_backward(long long v) {
    visited[v] = false;
    group_num[v] = group_cnt;
    for (long long w : g_rev[v])
      if (visited[w]) fill_backward(w);
  }
  long long calculate() {
    for (size_t i = 0; i < g.size(); ++i)
      if (!visited[i]) fill_forward(i);
    for (; !second.empty(); second.pop())
      if (visited[second.top()]) fill_backward(second.top()), ++group_cnt;
    return group_cnt;
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  vc<vc<long long> > a(n, vc<long long>(n));
  scc graph(n);
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      cin >> a[i][j];
      if (a[i][j] > 0) graph.add_edge(i, j);
    }
  }
  graph.calculate();
  if (graph.group_cnt > 1) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }
}
