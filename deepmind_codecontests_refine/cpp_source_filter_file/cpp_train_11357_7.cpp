#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mod = 1000000007;
const long long linf = 0x3f3f3f3f3f3f3f3f;
const int N = 300100;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool eq[310][310];
string s[310];
int dp[310][310];
int n;
int all;
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i], all += int(s[i].size());
  all += n - 1;
  for (int i = 0; i < n; i++) {
    eq[i][i] = 1;
    for (int j = i + 1; j < n; j++) {
      eq[i][j] = eq[j][i] = s[i] == s[j];
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = n - 1; j >= 0; j--) {
      if (eq[i][j]) dp[i][j] = dp[i + 1][j + 1] + 1;
    }
  }
  int ans = all;
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += int(s[i].size());
      int cnt = 1;
      int sz = j - i + 1;
      for (int k = j + 1; k < n; k++) {
        if (dp[i][k] >= sz) {
          cnt++;
          k += sz;
        }
      }
      int aux = all - sum * cnt + cnt;
      if (cnt > 1) ans = min(ans, aux);
    }
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  ;
  int t_ = 1;
  while (t_--) solve();
  return 0;
}
