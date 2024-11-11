#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n, a[3][N], used[N];
vector<int> pos[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    pos[i].clear();
    used[i] = 0;
  }
  for (int i = 1; i <= n; i++) cin >> a[1][i];
  for (int i = 1; i <= n; i++) cin >> a[2][i];
  for (int i = 1; i <= n; i++) {
    pos[a[1][i]].push_back(i);
    pos[a[2][i]].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    if (pos[i].size() != 2) {
      cout << -1 << endl;
      return;
    }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    vector<int> x[2];
    int v = i, val = a[1][i];
    if (used[i]) continue;
    do {
      x[(a[1][v] != val)].push_back(v);
      used[v] = 1;
      val = a[1][v] + a[2][v] - val;
      v = (pos[val][0] + pos[val][1] - v);
    } while (!used[v]);
    if (x[1].size() < x[0].size()) swap(x[1], x[0]);
    for (int j = 0; j < x[0].size(); j++) ans.push_back(x[0][j]);
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
