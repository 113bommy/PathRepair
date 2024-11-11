#include <bits/stdc++.h>
using namespace std;
const int MAXN = 21;
double dp[1 << MAXN], a[MAXN], l, r, x[MAXN], y[MAXN];
double calc(int id, double st) {
  double newAngle = a[id] - atan2(x[id] - st, y[id]);
  if (newAngle * 2 >= M_PI) return r;
  return tan(newAngle) * y[id] + x[id];
}
int main() {
  int n;
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> a[i], a[i] *= M_PI / 180.0;
  for (int i = 0; i < (1 << n); i++) {
    dp[i] = l;
    for (int j = 0; j < MAXN; j++)
      if (i & (1 << j)) dp[i] = max(dp[i], calc(j, dp[i - (1 << j)]));
  }
  cout << setprecision(9) << fixed << min(r, dp[(1 << n) - 1]) - l << endl;
  return 0;
}
