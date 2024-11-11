#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int maxn = 100100;
int n, k, ans, dp[maxn];
string s, t;
inline bool check(int a) {
  for (int i = 0; i < n; i++)
    if (s[i] != t[(i - a + n) % n]) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> t;
  cin >> k;
  n = s.size();
  dp[0] = 1;
  for (int S = 1, S1 = 0, i = 1; i <= k; i++) {
    S1 = 0;
    for (int j = n - 1; j >= 0; j--)
      dp[j] = ((S - dp[j] % M) + M) % M, S1 = (S1 + dp[j]) % M;
    S = S1;
  }
  for (int i = 0; i < n; i++) {
    if (check(i)) ans = (ans + dp[i]) % M;
  }
  cout << ans << endl;
  return 0;
}
