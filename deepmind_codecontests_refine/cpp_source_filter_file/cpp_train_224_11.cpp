#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int inf = 1e9;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int mxl = -inf, mnr = inf;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      mxl = max(mxl, a);
      mnr = min(mnr, b);
    }
    if (n == 1) {
      cout << "0\n";
    } else {
      cout << abs(mxl - mnr) << '\n';
    }
  }
  return 0;
}
