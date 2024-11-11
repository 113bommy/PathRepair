#include <bits/stdc++.h>
using namespace std;
void doRoutine() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
signed main() {
  doRoutine();
  long long n, m;
  cin >> n >> m;
  vector<vector<long long> > g(n);
  vector<vector<long long> > gt(n);
  for (long long i = 0; i < n - 1; ++i) {
    long long a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    gt[b].push_back(a);
  }
  vector<bool> used(n);
  vector<long long> verts;
  for (long long v = 0; v < n; ++v) {
    if (!used[v]) {
      verts.push_back(v);
      for (auto u : g[v]) {
        used[u] = true;
      }
    }
  }
  reverse(verts.begin(), verts.end());
  vector<bool> chosen(n);
  for (auto v : verts) {
    bool flag = false;
    for (auto u : gt[v]) {
      if (chosen[u]) {
        flag = true;
      }
    }
    if (!flag) {
      chosen[v] = true;
    }
  }
  vector<long long> ans;
  for (long long v = 0; v < n; ++v) {
    if (chosen[v]) {
      ans.push_back(v + 1);
    }
  }
  cout << ans.size() << endl;
  for (auto el : ans) {
    cout << el << " ";
  }
  cout << endl;
  return 0;
}
