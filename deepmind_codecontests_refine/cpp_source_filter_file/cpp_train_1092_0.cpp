#include <bits/stdc++.h>
using namespace std;
double eps = 1e-6;
const int maxn = 110;
const int mod = 1e9 + 7;
int a[maxn], dp[maxn * maxn], cnt[310];
int main() {
  int n, T;
  scanf("%d%d", &n, &T);
  for (int i = 0; i <= n - 1; i++) scanf("%d", &a[i]), cnt[a[i]]++;
  int x = 0, c = 0;
  for (int i = 1; i <= 300; i++) {
    if (cnt[i] > c) x = i, c = cnt[i];
  }
  for (int i = 0; i <= n * n - 1; i++) {
    dp[i] = 1;
    int l = max(0, i - n);
    for (int j = l; j <= i - 1; j++)
      if (a[j % n] <= a[i % n]) dp[i] = max(dp[i], dp[j] + 1);
  }
  int ans = T;
  if (T <= n) {
    for (int i = n * (T - 1); i <= n * T - 1; i++) ans = max(ans, dp[i]);
    cout << ans << endl;
  } else {
    for (int i = n * (n - 1); i <= n * n - 1; i++) ans = max(ans, dp[i]);
    cout << ans + c * (T - n) << endl;
  }
  return 0;
}
