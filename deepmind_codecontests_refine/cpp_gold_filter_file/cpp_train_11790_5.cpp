#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> kingdoms(n);
  for (int i = 0; i < n; ++i) {
    int sz;
    cin >> sz;
    for (int j = 0; j < sz; ++j) {
      int x;
      cin >> x;
      --x;
      kingdoms[i].push_back(x);
    }
  }
  vector<int> d(n, false);
  vector<int> p(n, false);
  for (int i = 0; i < n; ++i) {
    for (auto val : kingdoms[i]) {
      if (!p[val]) {
        p[val] = true;
        d[i] = true;
        break;
      }
    }
  }
  int val = -1;
  for (int i = 0; i < n; ++i) {
    if (!p[i]) {
      val = i;
      break;
    }
  }
  if (val == -1) {
    cout << "OPTIMAL\n";
    return;
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    if (!d[i]) {
      cout << "IMPROVE\n" << i + 1 << ' ' << val + 1 << '\n';
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "OPTIMAL\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
