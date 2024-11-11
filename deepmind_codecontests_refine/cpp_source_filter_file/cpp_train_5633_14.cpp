#include <bits/stdc++.h>
using namespace std;
string a, b;
long long dp[5][20][3][3];
long long F(int cnt, int pos, bool lead, bool zero) {
  if (cnt > 3) {
    return 0;
  }
  if (pos >= (int)b.size()) {
    return lead;
  }
  long long& ret = dp[cnt][pos][lead][zero];
  if (ret != -1) {
    return ret;
  }
  ret = 0;
  for (int i = 0; i <= 9; i++) {
    if (zero == false && i > (b[pos] - '0')) break;
    if (i) {
      ret += F(cnt + 1, pos + 1, 1, zero == true ? zero : ((b[pos] - '0') > i));
    } else {
      ret += F(0, pos + 1, lead, zero == true ? zero : ((b[pos] - '0') > i));
    }
  }
  return ret;
}
void solve() {
  cin >> a >> b;
  for (int i = (int)a.size() - 1; i >= 0; i--) {
    if (a[i] == '0') {
      a[i] = '9';
      continue;
    }
    a[i]--;
    break;
  }
  memset(dp, -1, sizeof dp);
  long long ans = F(0, 0, 0, 0);
  swap(a, b);
  memset(dp, -1, sizeof dp);
  cout << ans - F(0, 0, 0, 0) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
