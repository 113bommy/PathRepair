#include <bits/stdc++.h>
using namespace std;
long long int l, r, h, n;
long long int dp[3000][3000];
long long int solve(long long int tim, long long int ar[],
                    long long int index) {
  tim %= h;
  long long int ans = 0;
  if (tim >= l && tim <= r) ans++;
  if (index == n) return ans;
  long long int hour = ar[index];
  if (dp[tim][index] != -1) return dp[tim][index];
  return dp[tim][index] = ans + max(solve(tim + hour - 1, ar, index + 1),
                                    solve(tim + hour, ar, index + 1));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> h >> l >> r;
  long long int ar[n];
  for (long long int i = 0; i < n; i++) cin >> ar[i];
  for (int i = 0; i < 3000; i++) {
    for (int j = 0; j < 3000; j++) dp[i][j] = -1;
  }
  int ans = 0;
  ans = solve(0, ar, 0);
  if (!l) ans++;
  cout << ans;
}
