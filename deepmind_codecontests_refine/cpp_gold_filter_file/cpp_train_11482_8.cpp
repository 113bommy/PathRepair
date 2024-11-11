#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) cin >> v[i];
  int secondGroup = -1;
  int root = 0;
  set<pair<int, int>> ht;
  for (int i = 1; i < n; i++) {
    if (v[i] != v[root]) {
      ht.insert({root + 1, i + 1});
      secondGroup = i + 1;
    }
  }
  if (secondGroup == -1) {
    cout << "NO" << endl;
    return;
  }
  cout << "YES\n";
  for (int i = 1; i < n; i++) {
    if (v[i] == v[root]) ht.insert({secondGroup, i + 1});
  }
  for (pair<int, int> edges : ht)
    cout << edges.first << " " << edges.second << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
