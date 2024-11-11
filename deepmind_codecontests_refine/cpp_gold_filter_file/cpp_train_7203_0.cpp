#include <bits/stdc++.h>
using namespace std;
const long long int N = 3e5 + 5;
void solve() {
  int n;
  cin >> n;
  string zx;
  int bal = 0, bal2 = 0, ans = 0;
  vector<string> v;
  for (int i = 0; i < n; i++) {
    cin >> zx;
    v.push_back(zx);
    if (zx.size() % 2 == 1) {
      bal++;
    }
    if (v[i].size() % 2 == 0) {
      int o = 0;
      for (auto i : zx) {
        if (i == '1') {
          o++;
        }
      }
      if (o % 2 == 1) {
        bal2++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (v[i].size() % 2 == 1) {
      ans++;
    }
    if (v[i].size() % 2 == 0) {
      int o = 0;
      for (auto i : v[i]) {
        if (i == '1') {
          o++;
        }
      }
      if (o % 2 == 0) {
        ans++;
      } else if (bal > 0) {
        ans++;
        bal--;
      } else if (bal2 >= 2) {
        ans += 2;
        bal2 -= 2;
      }
    }
  }
  cout << min(ans, n) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
