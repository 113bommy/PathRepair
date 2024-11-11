#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2000000];
int dem;
int maxa;
int dp[10000001];
void mmax(int &a, int b) { a = max(a, b); }
bool ok(int len) {
  for (int i = 0; i <= maxa; i++) dp[i] = 0;
  dp[len] = 1;
  for (int i = len + 1; i <= maxa; i++) {
    mmax(dp[i], dp[i - 1]);
    mmax(dp[i], dp[i >> 1] + dp[(i + 1) >> 1]);
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += dp[a[i]];
  return sum >= k;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], maxa = max(maxa, a[i]);
  int d = 1, c = 10000000, g, fin = -1;
  while (d <= c) {
    g = (d + c) / 2;
    if (ok(g)) {
      fin = g;
      d = g + 1;
    } else
      c = g - 1;
  }
  cout << fin;
  return 0;
}
