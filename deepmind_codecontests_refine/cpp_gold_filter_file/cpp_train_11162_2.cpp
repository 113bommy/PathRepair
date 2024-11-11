#include <bits/stdc++.h>
using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  if (n & 0x01) {
    cout << "NO" << '\n';
  } else {
    bool yes = true;
    for (int i = 0; i < n / 2; ++i) {
      if (x[i] + x[n / 2 + i] != x[0] + x[n / 2] ||
          y[i] + y[n / 2 + i] != y[0] + y[n / 2]) {
        yes = false;
        break;
      }
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
  return 0;
}
