#include <bits/stdc++.h>
using namespace std;
int n, ans[55];
long long k, f[55][2][2];
long long dp(int l, int r, int rev, int inv) {
  if (l > r) {
    return 1;
  }
  if (f[l][rev][inv] >= 0) {
    return f[l][rev][inv];
  }
  f[l][rev][inv] = 0;
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      if (ans[l] != -1 && ans[l] != i) {
        continue;
      }
      if (ans[r] != -1 && ans[r] != j) {
        continue;
      }
      if (!rev && i && !j) {
        continue;
      }
      if (!inv && i && j) {
        continue;
      }
      if (l == r && i != j) {
        continue;
      }
      int nxt1 = rev, nxt2 = inv;
      if (!rev && !i && j) {
        nxt1 = 1;
      }
      if (!inv && !i && !j) {
        nxt2 = 1;
      }
      f[l][rev][inv] += dp(l + 1, r - 1, nxt1, nxt2);
    }
  }
  return f[l][rev][inv];
}
int main() {
  cin >> n >> k;
  memset(ans, -1, sizeof(ans));
  ans[1] = 0;
  memset(f, -1, sizeof(f));
  if (dp(1, n, 0, 0) <= k) {
    puts("-1");
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    memset(f, -1, sizeof(f));
    ans[i] = 0;
    int x = dp(1, n, 0, 0);
    if (x <= k) {
      k -= x;
      ans[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d", ans[i]);
  }
  return 0;
}
