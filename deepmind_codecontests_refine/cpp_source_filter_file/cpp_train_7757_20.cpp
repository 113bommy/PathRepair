#include <bits/stdc++.h>
using namespace std;
long long P = 1e9 + 7;
const int sqr = 500;
const int arrn = 4e6 + 5;
const int arrn2 = 6e3 + 5;
void solve() {
  int n, m, k;
  cin >> n >> m;
  k = n - m;
  vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i < k + 1; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % P;
      if (j < k) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % P;
    }
  }
  string in;
  cin >> in;
  int tem = 0, mn = 0;
  for (auto i : in) {
    if (i == '(')
      tem++;
    else
      tem--;
    mn = min(tem, mn);
  }
  long long out = 0;
  for (int i = 0; i < k + 1; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (j + tem < k + 1 && j >= mn && j + tem >= 0) {
        out = out + (dp[i][j] * dp[k - i][j + tem]) % P;
        out %= P;
      }
    }
  }
  if (out < 0) out += P;
  cout << out;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
