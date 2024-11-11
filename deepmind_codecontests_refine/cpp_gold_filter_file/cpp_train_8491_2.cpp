#include <bits/stdc++.h>
using namespace std;
vector<vector<int64_t> > gr;
vector<int64_t> c;
vector<bool> same;
void dfss(int64_t v, int64_t pr) {
  for (int64_t i = 0; i < gr[v].size(); i++)
    if (gr[v][i] != pr) {
      dfss(gr[v][i], v);
      if (!same[gr[v][i]] || c[gr[v][i]] != c[v]) same[v] = false;
    }
}
int64_t dfs(int64_t v, int64_t pr) {
  bool crr = false;
  int64_t found = 0;
  for (int64_t i = 0; i < gr[v].size(); i++)
    if (gr[v][i] != pr) {
      if (same[gr[v][i]]) {
        if (c[gr[v][i]] != c[v])
          if (found)
            return 0;
          else
            crr = true;
      } else {
        if (crr || found)
          return 0;
        else {
          found = dfs(gr[v][i], v);
          if (!found || found != gr[v][i] + 1 && c[v] != c[gr[v][i]]) return 0;
        }
      }
    }
  if (crr)
    return v + 1;
  else
    return found;
}
int32_t main() {
  int64_t n;
  cin >> n;
  gr.resize(n);
  c.resize(n);
  same.resize(n, 1);
  for (int64_t i = 0; i < n - 1; i++) {
    int64_t u, v;
    cin >> u >> v;
    gr[u - 1].push_back(v - 1);
    gr[v - 1].push_back(u - 1);
  }
  for (int64_t i = 0; i < n; i++) {
    cin >> c[i];
  }
  dfss(0, -1);
  int64_t t = dfs(0, -1);
  if (same[0])
    cout << "YES" << endl << 1;
  else if (t)
    cout << "YES" << endl << t;
  else
    cout << "NO" << endl;
  return 0;
}
