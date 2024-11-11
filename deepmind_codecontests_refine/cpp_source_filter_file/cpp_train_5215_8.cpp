#include <bits/stdc++.h>
using namespace std;
string k;
int dp[200005];
int mx[200005];
int p[200005];
int lst[3];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> k;
  for (int i = 0; i < k.length(); ++i) p[i] = (p[i - 1] + k[i] - '0') % 3;
  memset(lst, -1, sizeof lst);
  int ans = 0;
  for (int i = 0; i < k.length(); ++i) {
    if (lst[p[i]] != -1) {
      dp[i] = max(dp[i], mx[lst[p[i]]] + 1);
    }
    if (p[i] == 0) dp[i] = max(mx[i - 1], 1);
    mx[i] = max(mx[i - 1], dp[i]);
    lst[p[i]] = i;
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
