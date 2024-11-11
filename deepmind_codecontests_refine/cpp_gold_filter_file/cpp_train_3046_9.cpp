#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, k, mn = -1, mx = 0;
    cin >> n >> k;
    map<int, int> x;
    for (int j = 0; j < n; j++) {
      int t;
      cin >> t;
      t = t % k;
      x[t]++;
      if (mx <= x[t] && t != 0) {
        if (mx == x[t])
          mn = max(mn, k - t);
        else
          mn = k - t;
        mx = x[t];
      }
    }
    if (mx)
      cout << k * (mx - 1) + mn + 1 << endl;
    else
      cout << 0 << endl;
  }
}
