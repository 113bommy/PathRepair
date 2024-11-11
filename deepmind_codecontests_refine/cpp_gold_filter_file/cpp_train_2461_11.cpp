#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, maxn = 710;
long long sum[maxn][2], dp[maxn][2];
string s;
inline void Update(long long &x, long long y) { x = (x + y) % mod; }
void Clear() {
  memset(dp, 0, sizeof(dp));
  memset(sum, 0, sizeof(sum));
  dp[0][0] = 1;
}
int main() {
  cin >> s;
  int len = s.length();
  long long ans = 0;
  for (int l = 1; l <= 9; l++) {
    Clear();
    for (int i = 0; i < len; i++)
      for (int j = 0; j < 2; j++)
        for (int k = 0; k <= 9; k++) {
          if (!j && k > s[i] - '0') continue;
          Update(dp[i + 1][j | k < s[i] - '0'], dp[i][j]);
          if (k < l)
            Update(sum[i + 1][j | k < s[i] - '0'], sum[i][j]);
          else
            Update(sum[i + 1][j | k < s[i] - '0'],
                   (sum[i][j] * 10 + dp[i][j]) % mod);
        }
    Update(ans, sum[len][0]);
    Update(ans, sum[len][1]);
  }
  cout << ans << endl;
  return 0;
}
