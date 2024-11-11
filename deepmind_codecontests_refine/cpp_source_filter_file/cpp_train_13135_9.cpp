#include <bits/stdc++.h>
using namespace std;
int a[1000010];
struct _ {
  int max_, se;
  _ operator+(_ ob) {
    _ rv;
    if (max_ == ob.max_) {
      rv.max_ = max_;
      rv.se = max(se, ob.se);
      return rv;
    }
    if (max_ < ob.max_) {
      rv.max_ = ob.max_;
      rv.se = max(ob.se, max_);
    } else {
      rv.max_ = max_;
      rv.se = max(se, ob.max_);
    }
    return rv;
  }
};
_ dp[2048576];
int main() {
  int n;
  scanf("%d", &n);
  int i;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    dp[a[i]] = dp[a[i]] + (_){i, 0};
  }
  int j;
  for (i = 2048575; i >= 0; i--) {
    for (j = 0; j < 21; j++) {
      if (i & 1 << j) {
        dp[i ^ (1 << j)] = dp[i ^ (1 << j)] + dp[i];
      }
    }
  }
  int tmp, ans = 0;
  for (i = 1; i <= n - 2; i++) {
    tmp = 0;
    for (j = 20; j >= 0; j--) {
      if (i & 1 << j) continue;
      tmp ^= 1 << j;
      if (dp[tmp].se < i) tmp ^= 1 << j;
    }
    ans = max(ans, tmp | a[i]);
  }
  printf("%d\n", ans);
  return 0;
}
