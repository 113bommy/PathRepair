#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2>& p) {
  out << "{" << p.first << ", " << p.second << "} ";
  return out;
}
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& arr) {
  for (auto& i : arr) in >> i;
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& arr) {
  for (auto i : arr) out << i << ' ';
  out << '\n';
  return out;
}
vector<int64_t> cl;
vector<vector<int64_t>> g;
vector<int64_t> ans;
void push(int64_t v) {
  ans.push_back(v + 1);
  cl[v] = -cl[v];
}
void dfs(int64_t v, int64_t pr = -1) {
  push(v);
  for (auto u : g[v]) {
    if (u != pr) {
      dfs(u, v);
    }
  }
  if (pr != -1) {
    if (cl[v] == -1) {
      push(pr);
      push(v);
    }
    push(pr);
  }
}
signed main() {
  int64_t n;
  cin >> n;
  g.resize(n);
  cl.resize(n);
  cin >> cl;
  for (int64_t i = 0; i < n - 1; ++i) {
    int64_t a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cl[0] *= -1;
  dfs(0);
  if (cl[0] == -1) {
    push(g[0][0]), push(0), push(g[0][0]);
  }
  cout << ans << '\n';
  return 0;
}
