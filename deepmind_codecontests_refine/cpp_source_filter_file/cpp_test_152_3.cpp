#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, inf = 1e9;
int n, dp[N][2], w[N][2], lst[N][2], a[N], ns[N];
void Main() {
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i], w[i][0] = a[i], w[i][1] = -a[i];
  for (int i = (0); i <= (n); i++) dp[i][0] = dp[i][1] = inf;
  w[0][0] = w[0][1] = -inf;
  dp[0][0] = dp[0][1] = -inf;
  for (int i = (1); i <= (n); i++) {
    for (int a = (0); a <= (1); a++)
      for (int b = (0); b <= (1); b++)
        if (w[i][a] > w[i - 1][b] && dp[i][a] > dp[i - 1][b])
          dp[i][a] = dp[i - 1][b], lst[i][a] = b;
    for (int a = (0); a <= (1); a++)
      for (int b = (0); b <= (1); b++)
        if (w[i][a] > dp[i - 1][b] && dp[i][a] > w[i - 1][b])
          dp[i][a] = w[i - 1][b], lst[i][a] = b;
  }
  if (dp[n][0] == inf || dp[n][1] == inf)
    cout << "NO\n";
  else {
    cout << "YES\n";
    int o = dp[n][0] == inf ? 1 : 0;
    for (int i = (n); i >= (1); i--) ns[i] = w[i][o], o = lst[i][o];
    for (int i = (1); i <= (n); i++) cout << ns[i] << ' ';
    cout << '\n';
  }
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) Main();
  return 0;
}
