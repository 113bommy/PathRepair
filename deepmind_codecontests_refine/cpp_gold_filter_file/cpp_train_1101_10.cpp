#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  long long b1, q, l, m;
  cin >> b1 >> q >> l >> m;
  unordered_set<long long> bad;
  long long ba[1010100];
  for (int i = 0; i < m; ++i) {
    cin >> ba[i];
    bad.insert(ba[i]);
  }
  if (q == -1) {
    if (abs(b1) > l)
      cout << "0" << endl;
    else {
      if (bad.count(b1) > 0 && bad.count(-b1) > 0) {
        cout << "0" << endl;
      } else if (bad.count(b1) > 0 && bad.count(-b1) == 0) {
        cout << "inf" << endl;
      } else if (bad.count(b1) == 0 && bad.count(-b1) > 0) {
        cout << "inf" << endl;
      } else if (bad.count(b1) == 0 && bad.count(-b1) == 0) {
        cout << "inf" << endl;
      }
    }
    return 0;
  }
  if (abs(b1) > l) {
    cout << 0 << endl;
    return 0;
  }
  int ans = 0;
  long long b = b1;
  if (bad.count(b) == 0) ans++;
  unordered_set<long long> vis;
  vis.insert(b);
  while (true) {
    b = b * q;
    if (abs(b) > l) break;
    if (vis.count(b)) {
      if (bad.count(b)) {
        cout << ans << endl;
      } else {
        cout << "inf" << endl;
      }
      return 0;
    }
    vis.insert(b);
    if (bad.count(b) == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}
