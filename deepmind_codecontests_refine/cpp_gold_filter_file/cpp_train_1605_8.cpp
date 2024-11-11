#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, r, q1, q2, w;
  cin >> n >> l >> r >> q1 >> q2;
  vector<int> wt;
  vector<int> dp1(n), dp2(n);
  for (int i = 0; i < n; i++) {
    cin >> w;
    wt.push_back(w);
  }
  dp1[0] = wt[0];
  dp2[n - 1] = wt[n - 1];
  for (int i = 1; i < n; i++) {
    dp1[i] = dp1[i - 1] + wt[i];
  }
  for (int i = n - 2; i >= 0; i--) {
    dp2[i] = dp2[i + 1] + wt[i];
  }
  int mn = 2000000000;
  int rs;
  for (int k = 1; k < n; k++) {
    rs = 0;
    if (n >= 2 * k) {
      rs += dp2[k] * r;
      rs += dp1[k - 1] * l;
      if ((n - 2 * k - 1) * q2 > 0) {
        rs += (n - 2 * k - 1) * q2;
      }
    } else {
      rs += dp2[k] * r;
      rs += dp1[k - 1] * l;
      if ((2 * k - n - 1) * q1 > 0) {
        rs += (2 * k - n - 1) * q1;
      }
    }
    if (rs < mn) {
      mn = rs;
    }
  }
  rs = dp1[n - 1] * l + q1 * (n - 1);
  if (rs < mn) {
    mn = rs;
  }
  rs = dp2[0] * r + q2 * (n - 1);
  if (rs < mn) {
    mn = rs;
  }
  cout << mn;
}
