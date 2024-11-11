#include <bits/stdc++.h>
using namespace std;
long long T, X;
vector<long long> lucky, l = {0, 4, 7};
vector<long long> ans(6);
bool DP[10000][7];
bool dp(long long x, int i) {
  if (i == 6) return (x == 0);
  if (!DP[x][i]) return false;
  for (long long y : lucky) {
    if (y > x) break;
    if (dp(x - y, i + 1)) {
      ans[i] = y;
      return true;
    }
  }
  return DP[x][i] = false;
}
int main() {
  for (int i1 = 0; i1 < (int)3; i1++)
    for (int i2 = 0; i2 < (int)3; i2++)
      for (int i3 = 0; i3 < (int)3; i3++)
        lucky.push_back(l[i1] * 100 + l[i2] * 10 + l[i3]);
  cin >> T;
  while (T--) {
    memset(DP, true, sizeof DP);
    ans.assign(6, 0ll);
    cin >> X;
    long long X1 = X % 4000ll, X2 = X - X1;
    if (!dp(X1, 0)) {
      X1 += 4000ll;
      X2 -= 4000ll;
      if (X2 < 0 or !dp(X1, 0)) {
        cout << -1 << '\n';
        continue;
      }
    }
    long long pow = 1000;
    X2 = X2 / 4000ll;
    while (X2) {
      long long d = X2 % 10ll;
      X2 /= 10ll;
      if (d > 6) {
        for (int i = 0; i < (int)4; i++) ans[i + 2] += 7ll * pow;
        d -= 7ll;
      }
      for (int i = 0; i < (int)d; i++) ans[i] += 4ll * pow;
      pow *= 10ll;
    }
    for (int i = 0; i < (int)6; i++) cout << ans[i] << ' ';
    cout << '\n';
  }
}
