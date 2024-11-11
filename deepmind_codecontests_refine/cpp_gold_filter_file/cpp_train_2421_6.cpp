#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, q, i, j, dp[2], ans;
string s[2], t[2];
int solve() {
  memset(dp, 0, sizeof(dp));
  int i, j;
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) dp[t[0][i] == 'B']++;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    dp[s[0][i] == 'B']++;
    dp[s[1][i] == 'B']++;
    if (i < n) {
      dp[0] = min(dp[0], dp[1] + m);
      dp[1] = min(dp[1], dp[0] + m);
    }
  }
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) dp[t[1][i] == 'B']++;
  return min(dp[0], dp[1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  ;
  cin >> n >> m >> q;
  cin >> s[0] >> s[1];
  s[0] = " " + s[0];
  s[1] = " " + s[1];
  cin >> t[0] >> t[1];
  t[0] = " " + t[0];
  t[1] = " " + t[1];
  ans = solve();
  swap(s[0], t[0]);
  swap(s[1], t[1]);
  swap(n, m);
  ans = min(ans, solve());
  cout << ans << endl;
  return 0;
}
