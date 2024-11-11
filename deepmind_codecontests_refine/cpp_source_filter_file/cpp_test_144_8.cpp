#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    int md = n % m;
    int flr = n / m, cl = (n + m - 1) / m;
    int ix = 0;
    for (int i = 0; i < k; i++) {
      int cur = ix;
      for (int j = 0; j < md; j++) {
        cout << cl << ' ';
        for (int l = 0; l < cl; l++) {
          cout << cur + 1 << ' ';
          cur += 1;
          cur %= n;
        }
        cout << '\n';
      }
      for (int j = 0; j < flr - md; j++) {
        cout << flr << ' ';
        for (int l = 0; l < flr; l++) {
          cout << cur + 1 << ' ';
          cur += 1;
          cur %= n;
        }
        cout << '\n';
      }
      ix += md * cl;
      ix %= n;
    }
    cout << '\n';
  }
  return 0;
}
