#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e4 + 1;
const int mxm = 11 + 5;
int n;
int dp[mxm * 2], dp2[mxm * 2];
void solve() {
  cin >> n;
  memset(dp, 0x3f, sizeof(dp));
  memset(dp2, 0x3f, sizeof(dp));
  int *curr = dp, *prev = dp2;
  curr[0] = 0;
  for (int i = 0; i < n; ++i) {
    swap(prev, curr);
    memset(curr, 0x3f, sizeof(int) * 2 * mxm);
    int x;
    cin >> x;
    for (int j = 0; j < 2 * mxm; ++j) {
      curr[max(0, j - x)] = min(curr[max(0, j - x)], prev[j] + max(0, x - j));
      if (j + x < 2 * mxm)
        curr[j + x] = min(curr[j + x], prev[j] + max(0, j + x - prev[j]));
    }
  }
  int mn = INT_MAX;
  for (int i = 0; i < 2 * mxm; ++i) mn = min(mn, curr[i]);
  cout << mn << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
