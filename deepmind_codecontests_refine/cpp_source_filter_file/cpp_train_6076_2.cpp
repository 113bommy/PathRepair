#include <bits/stdc++.h>
using namespace std;
const int N = 13e5 + 5;
void solve() {
  int n, m;
  cin >> n >> m;
  if (n == 2) {
    cout << 0;
    return;
  }
  vector<int> z(n);
  for (int &it : z) {
    cin >> it;
  }
  vector<int> z1 = z;
  sort(z.begin(), z.end());
  int ans = z[n - 1] + z[n - 2] - z[0] - z[1];
  int f = max(z[n - 1] + z[n - 2], z[n - 1] + m + z[0]);
  int f1 = min(z[1] + z[2], z[1] + z[0] + m);
  cout << min(ans, f - f1) << "\n";
  for (int i = 0; i < n; i++) {
    if (min(ans, f - f1) != ans && z[0] == z1[i]) {
      cout << "2 ";
      while (++i < n) {
        cout << "1 ";
      }
    } else {
      cout << "1 ";
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int32_t tq = 1;
  for (; tq; tq--) {
    solve();
  }
}
