#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 1e5;
void solve() {
  cin >> n >> m;
  vector<vector<pair<int, int>>> v(n + 1);
  vector<bool> row(maxn, false);
  for (int i = 1; i <= n; ++i) {
    v[i].push_back(make_pair(i, i));
    row[i] = true;
  }
  for (int _ = 0; _ < m; ++_) {
    int a, b;
    cin >> a >> b;
    for (int i = 1; i < maxn; ++i)
      if (row[i] == false) {
        v[a].push_back(make_pair(i, a));
        v[b].push_back(make_pair(i, b));
        row[i] = true;
        break;
      }
  }
  for (int i = 1; i <= n; ++i) {
    cout << ((long long)v[i].size()) << endl;
    for (pair<int, int> el : v[i]) cout << el.first << ' ' << el.second << endl;
  }
  cout << endl;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ;
  int tt;
  tt = 1;
  for (int i = 1; i <= tt; ++i) {
    solve();
  }
  return 0;
}
