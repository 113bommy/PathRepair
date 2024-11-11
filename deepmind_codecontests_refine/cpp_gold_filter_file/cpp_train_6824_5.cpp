#include <bits/stdc++.h>
using namespace std;
string strings[int(1e5 + 10)];
long long cost[int(1e5 + 10)], n;
long long dp[2 * int(1e5 + 10)][2];
long long change(int indx, int ch) {
  long long &res = dp[indx][ch];
  if (res != -1) return res;
  if (indx == n) return 0;
  long long ans = 1e18;
  if (ch) {
    string test = strings[indx - 1], test2 = strings[indx];
    reverse(test.begin(), test.end());
    reverse(test2.begin(), test2.end());
    if (strings[indx] >= test) {
      ans = min(ans, change(indx + 1, 0));
    }
    if (test2 >= test) {
      ans = min(ans, cost[indx] + change(indx + 1, 1));
    }
  } else {
    string test = strings[indx - 1], test2 = strings[indx];
    reverse(test2.begin(), test2.end());
    if (strings[indx] >= test) {
      ans = min(ans, change(indx + 1, 0));
    }
    if (test2 >= test) {
      ans = min(ans, cost[indx] + change(indx + 1, 1));
    }
  }
  return res = ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cost[i];
  for (int i = 0; i < n; i++) cin >> strings[i];
  memset(dp, -1, sizeof dp);
  long long ans = min(change(1, 0), change(1, 1) + cost[0]);
  if (ans >= 1e18)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
