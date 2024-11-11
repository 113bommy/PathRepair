#include <bits/stdc++.h>
using namespace std;
int dp[100010][3];
vector<int> v;
int n;
int solve(int i, int op, int last) {
  if (i == n) {
    return 0;
  }
  if (dp[i][op] != -1) {
    return dp[i][op];
  }
  int ans = 0x3f3f3f3f;
  int aux = op;
  if (aux == 2) {
    aux = -1;
  }
  int aux2 = last;
  if (aux2 == 2) {
    aux2 = -1;
  }
  if ((v[i] - v[i - 1] + 1 - aux) == (v[i - 1] + aux - v[i - 2] - aux2)) {
    ans = min(ans, 1 + solve(i + 1, 1, op));
  }
  if ((v[i] - v[i - 1] - aux) == (v[i - 1] + aux - v[i - 2] - aux2)) {
    ans = min(ans, solve(i + 1, 0, op));
  }
  if ((v[i] - v[i - 1] - 1 - aux) == (v[i - 1] + aux - v[i - 2] - aux2)) {
    ans = min(ans, 1 + solve(i + 1, 2, op));
  }
  return dp[i][op] = ans;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  v.resize(n, 0);
  for (int i = 0; i < (n); i++) {
    cin >> v[i];
  }
  memset(dp, -1, sizeof dp);
  int ans = 0x3f3f3f3f;
  for (int i = 0; i < (3); i++) {
    for (int j = 0; j < (3); j++) {
      memset(dp, -1, sizeof dp);
      int aux = (i > 0) + (j > 0);
      ans = min(ans, aux + solve(2, i, j));
    }
  }
  if (n == 2) {
    cout << 0 << '\n';
    return 0;
  }
  if (ans > n + 1) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  return 0;
}
