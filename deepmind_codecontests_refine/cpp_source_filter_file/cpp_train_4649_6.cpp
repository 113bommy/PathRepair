#include <bits/stdc++.h>
using namespace std;
int n, a[300030], ans[300030], m;
long long dp[300030];
bool d[300030];
void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}
void opt(int pos) {
  if (pos <= 0 || pos == n) return;
  int tmp = min(a[pos], a[pos + 1]);
  if (!tmp) return;
  ans[++m] = pos;
  a[pos] -= tmp, a[pos + 1] -= tmp;
}
void solve() {
  for (int i = 1; i <= n; ++i) {
    long long one = dp[max(i - 2, 0)] + a[i],
              two = dp[max(i - 3, 0)] + max(a[i - 1], a[i]);
    dp[i] = min(one, two);
    d[i] = dp[i] == one;
  }
  for (int i = (dp[n] < dp[n - 1]) ? n : n - 1; i > 0;) {
    if (d[i]) {
      opt(i);
      opt(i - 1);
      i -= 2;
    } else {
      opt(i);
      opt(i - 1);
      opt(i - 2);
      i -= 3;
    }
  }
  printf("%d\n", m);
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
}
int main() {
  init();
  solve();
  return 0;
}
