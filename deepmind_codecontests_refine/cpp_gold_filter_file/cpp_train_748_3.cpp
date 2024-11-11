#include <bits/stdc++.h>
using namespace std;
int dp[105][105][105][3], a[105], n;
bool used[105];
int go(int pos, int ones, int zeros, int last) {
  if (ones < 0 || zeros < 0) return 1e9;
  if (pos == n) return 0;
  int &ret = dp[pos][ones][zeros][last];
  if (ret != -1) return ret;
  ret = 1e9;
  if (used[pos])
    return ret =
               go(pos + 1, ones, zeros, a[pos]) + (a[pos] != last && last != 2);
  int cur1 = go(pos + 1, ones - 1, zeros, 1) + (last == 0),
      cur2 = go(pos + 1, ones, zeros - 1, 0) + (last == 1);
  ret = min(cur1, cur2);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  int zeros = n / 2, ones = n - zeros;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (!a[i]) continue;
    a[i] = a[i] & 1;
    if (a[i])
      ones--;
    else
      zeros--;
    used[i] = true;
  }
  cout << go(0, ones, zeros, 2);
  return 0;
}
