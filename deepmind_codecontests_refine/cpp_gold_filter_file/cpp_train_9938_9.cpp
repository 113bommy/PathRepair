#include <bits/stdc++.h>
using namespace std;
int n, a, b, k;
long long int dp[5005][5005];
long long int cumm[5005];
pair<int, int> seg[5005];
int main() {
  cin >> n >> a >> b >> k;
  for (int pos = 1; pos <= n; pos++) {
    int l = pos - 1;
    while (l > 0) {
      if (abs(pos - l) >= abs(pos - b)) break;
      l--;
    }
    l++;
    int r = pos + 1;
    while (r <= n) {
      if (abs(pos - r) >= abs(pos - b)) break;
      r++;
    }
    r--;
    if (l == pos) l++;
    if (r == pos) r--;
    seg[pos] = make_pair(l, r);
  }
  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  for (int j = 1; j <= k; j++) {
    for (int gg = 1; gg <= n; gg++) {
      cumm[gg] = dp[gg][j - 1];
      cumm[gg] += cumm[gg - 1];
      cumm[gg] %= 1000000007;
    }
    for (int pos = 1; pos <= n; pos++) {
      pair<int, int> kop = seg[pos];
      int l1 = kop.first;
      int r1 = kop.second;
      if (l1 > r1) continue;
      dp[pos][j] = (cumm[r1] - cumm[l1 - 1] + 1000000007) % 1000000007;
      if (l1 < pos && r1 > pos)
        dp[pos][j] = (dp[pos][j] - dp[pos][j - 1] + 1000000007) % 1000000007;
    }
  }
  cout << dp[a][k] << '\n';
  return 0;
}
