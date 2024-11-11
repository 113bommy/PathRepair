#include <bits/stdc++.h>
using namespace std;
long long z, r, n, ma[100005], t[100005], x[100005], y[100005], val[100005],
    dp[505][505], ans;
int main() {
  ios_base::sync_with_stdio(false);
  long long tt = 1;
  while (tt--) {
    cin >> r >> n;
    t[1] = 0, x[1] = 1, y[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
      cin >> t[i] >> x[i] >> y[i];
      val[i] = -1e9;
    }
    for (int i = 2; i <= n + 1; i++) {
      for (int j = i - 1; j >= 1 && i - j <= 2 * r; j--) {
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
          val[i] = max(val[i], val[j] + 1);
      }
      if (i > 2 * r) val[i] = max(val[i], 1 + ma[i - 2 * r]);
      ma[i] = max(val[i], ma[i - 1]);
    }
    cout << ans << endl;
  }
}
