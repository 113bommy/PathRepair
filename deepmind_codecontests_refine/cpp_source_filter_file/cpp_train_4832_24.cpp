#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 10, MAX = 2e6 + 1e4, MOD = 1e9 + 7, MAXL = 25;
void OUT(long double o, int x) {
  cout << fixed << setprecision(x) << o;
  return;
}
long long a[MAX], dp[MAX];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    dp[a[i]]++;
  }
  for (int i = 1; i <= 2e6; i++) dp[i] += dp[i - 1];
  long long ans = 0;
  for (int i = 2; i <= 1e6; i++) {
    long long t = 1;
    if (dp[i - 1]) t = 0;
    if (k >= i - 1) {
      if (t) ans = i;
      continue;
    }
    for (int j = 1; i * j <= 1e6; j++)
      if (dp[i * (j + 1) - 1] - dp[i * j + k]) t = 0;
    if (t) ans = i;
  }
  cout << ans;
  return 0;
}
