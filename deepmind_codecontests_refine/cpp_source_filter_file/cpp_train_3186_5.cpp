#include <bits/stdc++.h>
using namespace std;
int a[5005];
int dp[5005];
int ma[5005];
int mi[5005];
int s[5005];
int n;
int l, r;
int main() {
  for (int i = 1; i <= 5005; i++) {
    dp[i] = 0;
    mi[i] = -1;
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ma[a[i]] = i;
    s[i] = s[i - 1];
    if (mi[a[i]] == -1) {
      mi[a[i]] = i;
      s[i] = s[i] ^ a[i];
    }
  }
  for (int i = 1; i <= n; i++) {
    l = 1e7;
    r = -1;
    dp[i] = max(dp[i], dp[i - 1]);
    for (int j = i; j <= n; j++) {
      l = min(l, mi[a[j]]);
      r = max(r, ma[a[j]]);
      if (l < i) break;
      if (r > j) continue;
      dp[j] = max(dp[j], dp[i - 1] + (s[j] ^ s[i - 1]));
    }
  }
  cout << dp[n] << endl;
  return 0;
}
