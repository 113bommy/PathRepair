#include <bits/stdc++.h>
using namespace std;
int n, m, col[202], row[202], a[202][202];
void check() {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      v.push_back({a[i][j] ^ row[i] ^ col[j]});
    }
  }
  if (is_sorted((v).begin(), (v).end())) {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << row[i];
    cout << '\n';
    for (int i = 0; i < m; i++) cout << col[i];
    cout << '\n';
    exit(0);
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int l = 0; l < m; l++) {
    for (int j = 0; j < m; j++) col[j] = !(a[0][j] ^ (j < l));
    for (int i = 1; i < n; i++) row[i] = !(a[i][0] ^ col[0]);
    check();
  }
  for (int l = 1; l < n + 1; l++) {
    for (int j = 0; j < m; j++) col[j] = a[0][j];
    for (int i = 0; i < n; i++) row[i] = (a[i][0] ^ col[0]) == (i >= l);
    check();
  }
  cout << "NO" << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
