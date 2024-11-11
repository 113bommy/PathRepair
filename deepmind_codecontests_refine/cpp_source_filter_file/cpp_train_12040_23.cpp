#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > dp;
int back(int u) {
  int pr = 1;
  while (u > 0) {
    int p = u % 10;
    u /= 10;
    if (p > 0) {
      pr *= p;
    }
  }
  if (pr >= 10) {
    return back(pr);
  }
  return pr;
}
int main() {
  dp.assign(10, vector<int>());
  for (int i = 1; i <= 1000000; i++) {
    int d = back(i);
    dp[d].push_back(i);
  }
  int q;
  cin >> q;
  int l, r, k;
  for (int i = 1; i <= q; i++) {
    cin >> l >> r >> k;
    int a = lower_bound(dp[k].begin(), dp[k].end(), r) - dp[k].begin();
    int b = upper_bound(dp[k].begin(), dp[k].end(), l) - dp[k].begin();
    cout << a - b << endl;
  }
  return 0;
}
