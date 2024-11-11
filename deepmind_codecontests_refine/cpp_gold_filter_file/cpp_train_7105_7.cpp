#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6;
const double PI = acos(-1.0);
ll read();
ll dp[N][2];
int main() {
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sum += x;
    dp[i][0] = dp[i - 1][0];
    dp[i][1] = dp[i - 1][1];
    if (i & 1) {
      dp[i][1] += x;
    } else {
      dp[i][0] += x;
    }
  }
  ll ans = min(dp[n - 2][1], dp[n - 1][0]);
  for (int i = 3; i <= n; i++) {
    ll cnt = 0;
    if (i & 1) {
      cnt += dp[n][1] - dp[i - 1][1];
      cnt += dp[i - 3][0];
    } else {
      cnt += dp[n][0] - dp[i - 1][0];
      cnt += dp[i - 3][1];
    }
    ans = min(ans, cnt);
  }
  cout << sum - ans << endl;
  return "BT7274", NULL;
}
inline ll read() {
  ll hcy = 0, dia = 1;
  char boluo = getchar();
  while (!isdigit(boluo)) {
    if (boluo == '-') dia = -1;
    boluo = getchar();
  }
  while (isdigit(boluo)) {
    hcy = hcy * 10 + boluo - '0';
    boluo = getchar();
  }
  return hcy * dia;
}
