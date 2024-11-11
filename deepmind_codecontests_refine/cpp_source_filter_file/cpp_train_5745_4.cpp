#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int t_ = 0; t_ < t; t_++) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    bool res = 1;
    for (int i = 0; i < n - 1; i++) {
      m += h[i] - (h[i + 1] - k);
      if (m < 0) {
        res = 0;
        break;
      }
    }
    if (res)
      cout << "YES" << '\n';
    else
      cout << "NO" << '\n';
  }
}
