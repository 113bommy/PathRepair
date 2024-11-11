#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1);
const int oo = 1e9, bpr = 1e6 + 3, N = 110;
inline void add(int &x, int y) {
  x += y;
  if (x >= bpr) x -= bpr;
}
int dp[N];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  int c, w, h;
  cin >> c >> w >> h;
  int bad = 1;
  for (int i = 1; i <= w + 1; ++i) bad = (bad * h) % bpr;
  dp[0] = 1;
  dp[N - 1] = 1;
  for (int i = 0; i <= c; ++i) {
    int pre = i - (w + 2);
    pre %= N;
    pre += N;
    pre %= N;
    add(dp[i % N], (bpr - dp[pre] * bad % bpr));
    dp[(i + 1) % N] = dp[i % N] * (h + 1) % bpr;
  }
  cout << dp[c % N];
  return 0;
}
