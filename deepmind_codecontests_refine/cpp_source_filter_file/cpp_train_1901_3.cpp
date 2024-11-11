#include <bits/stdc++.h>
using namespace std;
const long long N = 1000000007;
void dfs(int v, int p, vector<int> &d, const vector<vector<int> > &gr) {
  if (d[v] != -1) return;
  d[v] = d[p] + 1;
  for (int i = 0; i < gr[v].size(); ++i) {
    dfs(gr[v][i], v, d, gr);
  }
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > gr(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    gr[u].emplace_back(v);
    gr[v].emplace_back(u);
  }
  cout << "? " << n << endl << flush;
  for (int i = 0; i < n; ++i) cout << i + 1 << " ";
  cout << endl << flush;
  int f, mn, s = -1;
  cin >> f >> mn;
  --f;
  int l = mn / 2 + mn % 2, r = mn + 1;
  while (l < r - 1) {
    vector<int> d1(n, -1);
    dfs(f, f, d1, gr);
    int mid = (l + r) / 2;
    vector<int> sp;
    for (int i = 0; i < n; ++i) {
      if (d1[i] < mid) continue;
      sp.emplace_back(i);
    }
    if (sp.empty()) {
      r = mid;
    } else {
      cout << "? " << sp.size() << endl << flush;
      for (int i = 0; i < sp.size(); ++i) cout << sp[i] + 1 << " ";
      cout << endl << flush;
      int a, b;
      cin >> a >> b;
      --a;
      if (b == mn) {
        s = a;
        l = d1[s];
      } else {
        r = mid;
      }
    }
  }
  if (s == -1) s = f;
  vector<int> ds(n, -1), sp;
  dfs(s, s, ds, gr);
  for (int i = 0; i < n; ++i) {
    if (ds[i] == mn) sp.emplace_back(i);
  }
  cout << "? " << sp.size() << endl << flush;
  for (int i = 0; i < sp.size(); ++i) cout << sp[i] + 1 << " ";
  cout << endl << flush;
  int a, b;
  cin >> a >> b;
  --a;
  cout << "! " << a + 1 << " " << s + 1 << endl << flush;
  string t;
  cin >> t;
}
int main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
