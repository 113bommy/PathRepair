#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (auto &x : v) cin >> x;
  bool valid = true;
  for (int i = k - 1; i < n - 1; i++) {
    if (v[i] != v[i + 1]) {
      valid = false;
      break;
    }
  }
  if (!valid) {
    cout << -1 << endl;
    return;
  }
  int pos = k - 2;
  int target = v[k - 1];
  while (pos >= 0 && v[pos] == target) {
    pos--;
  }
  cout << pos + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
}
