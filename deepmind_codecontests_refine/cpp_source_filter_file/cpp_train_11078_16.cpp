#include <bits/stdc++.h>
using namespace std;
const int N = 50 * 1e4 + 9;
bool dp[N];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  dp[0] = 1;
  int mx = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    for (int j = mx += x; j >= x; --j) dp[j] |= dp[j - x];
  }
  int ans1, ans2 = 0;
  for (int i = 0;;) {
    bool ok = 0;
    for (int j = min(mx, i + d); j > i; --j) {
      if (dp[j]) {
        i = j;
        ans1 = i;
        ans2++;
        ok = 1;
        break;
      }
    }
    if (!ok) break;
  }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
