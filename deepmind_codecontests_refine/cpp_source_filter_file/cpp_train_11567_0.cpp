#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
using ll = long long;
const ll M = 10004205361450474;
ll dp[N][6], q[N];
int main() {
  ios::sync_with_stdio(false);
  for (int j = 1; j < 5; j++)
    for (int i = 1; i <= 10000; i++) {
      ll cur = min(i + dp[i][j - 1] - 1, 10000ll);
      dp[i][j] = dp[i][j - 1];
      for (int k = 1; k <= i; k++) {
        if (cur == 10000) {
          dp[i][j] += (dp[cur][j - 1] + 1) * (i - k + 1);
          break;
        }
        dp[i][j] += dp[cur][j - 1] + 1;
        cur = min(cur + dp[cur][j - 1] + 1, 10000ll);
      }
    }
  ll cur = 1;
  for (int i = 4; i >= 0; --i) {
    ll num = cur;
    q[0] = cur - 1;
    int idx = 0;
    for (int j = 1; j <= min(cur, 10000ll); j++) {
      num += dp[min(num, 10000ll)][i];
      if (num > M) break;
      q[++idx] = num;
      ++num;
    }
    cout << idx << ' ';
    for (int j = 1; j <= idx; j++) cout << q[j] << ' ';
    cout << endl;
    int pos;
    cin >> pos;
    if (pos < 0) return 0;
    cur = q[pos] + 1;
  }
  return 0;
}
