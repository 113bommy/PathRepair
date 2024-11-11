#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int tc, cs = 1, n, m, c;
int stair[N], elevator[N];
int dp[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> c;
  for (int i = 1; i < n; ++i) cin >> stair[i];
  for (int i = 1; i < n; ++i) cin >> elevator[i];
  int left = 0;
  int right = c;
  for (int i = 2; i <= n; ++i) {
    left = min(left + stair[i - 1], right + elevator[i - 1]);
    right = min(left + c, right + elevator[i - 1]);
    dp[i] = min(left, right);
  }
  for (int i = 1; i <= n; ++i) cout << dp[i] << " ";
  cout << endl;
  return 0;
}
