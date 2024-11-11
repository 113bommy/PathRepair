#include <bits/stdc++.h>
using namespace std;
int n, l, r, sum;
int dp[10010];
struct UNO {
  int b, h;
  UNO() {}
  bool operator<(const UNO &u) const {
    if (b != u.b) return b < u.b;
    return h > u.h;
  }
} uno[10010];
int main() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> uno[i].h;
    sum += uno[i].h;
  }
  for (int i = 1; i <= n; i++) cin >> uno[i].b;
  sort(uno + 1, uno + 1 + n);
  int ll = sum - r, rr = sum - l;
  l = ll, r = rr;
  for (int i = 1; i <= n; i++) dp[i] = -1e9;
  for (int i = 1; i <= n; i++)
    for (int h = sum - uno[i].h; ~h; h--)
      dp[h + uno[i].h] =
          max(dp[h + uno[i].h],
              dp[h] + (uno[i].b && l <= h + uno[i].h && h + uno[i].h <= r));
  cout << *max_element(dp, dp + sum + 1) << endl;
  return 0;
}
