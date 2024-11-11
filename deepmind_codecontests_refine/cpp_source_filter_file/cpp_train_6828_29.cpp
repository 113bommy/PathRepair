#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
void solve(int lol) {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int root = sqrt(n);
  int dp[n + 1][root + 1];
  for (int j = 1; j <= root; j++) {
    for (int p = n; p >= 1; p--)
      if (p + arr[p] + j > n)
        dp[p][j] = 1;
      else
        dp[p][j] = 1 + dp[p + arr[p] + j][j];
  }
  int q;
  cin >> q;
  while (q--) {
    int p, k;
    cin >> p >> k;
    if (k <= root)
      cout << dp[p][k] << endl;
    else {
      int ans = 0;
      while (p <= n) {
        p = p + arr[p - 1] + k;
        ans++;
      }
      cout << ans << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  for (int i = 1; i <= t; i++) solve(i);
}
