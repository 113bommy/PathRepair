#include <bits/stdc++.h>
using namespace std;
class DebugStream {
} LOG;
template <typename T>
DebugStream &operator<<(DebugStream &s, const T &) {
  return s;
}
const int maxN = 1e5 + 9, maxV = 1e6 + 9, MOD = 1e9 + 7, SQ = 335, lg = 20,
          bs = 29;
string st;
int n, dp[maxN][11];
const int key[11] = {-1, 9, 9, 10, 1, 4, 8, 2, 8, 4, 1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> st;
  n = st.size();
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = st[i] - '0' + 1; j < 11; j++) {
      int newK = (j + key[j] + st[i] - '0') % 11;
      dp[i][j] = dp[i + 1][newK] + 1;
    }
    if (st[i] != '0') ans += dp[i + 1][st[i] - '0'] + 1;
  }
  cout << ans << '\n';
}
