#include <bits/stdc++.h>
using namespace std;
int a[312345];
int u[312345];
int v[312345];
inline void solve() {
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  u[n - 1] = a[n - 1] - n;
  v[n - 1] = p + a[n - 1] - n;
  for (int i = n - 2; i >= 0; i--) {
    u[i] = max(u[i + 1], a[i] - i - 1);
    v[i] = min(v[i + 1], p + a[i] - i - 1);
  }
  vector<int> ans;
  int o = 0;
  for (int x = max(a[n - 1] - n - 1, 1); x < a[n - 1] - 1; ++x) {
    while (o < n) {
      if (a[o] > x) {
        break;
      }
      o++;
    }
    if (o >= p) {
      break;
    }
    if (x > u[o] && x < v[o]) {
      ans.push_back(x);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
