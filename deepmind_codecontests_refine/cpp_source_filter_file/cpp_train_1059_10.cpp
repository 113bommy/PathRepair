#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
void solve() {
  vector<int> z;
  z.push_back(0);
  int cng = 1, st = 0, prev, ad = 0;
  while (z.back() <= N) {
    st++;
    if (st == cng) {
      ad++;
      cng *= 10;
    }
    prev += ad;
    z.push_back(z.back() + prev);
  }
  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;
    int p = lower_bound(z.begin(), z.end(), x) - z.begin();
    x -= z[p - 1];
    for (int i = 1; i <= p; i++) {
      string f = to_string(i);
      int j = 0;
      while (j < f.size()) {
        x--;
        if (x == 0) {
          cout << f[j] << "\n";
          i = p + 1;
          break;
        }
        j++;
      }
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
