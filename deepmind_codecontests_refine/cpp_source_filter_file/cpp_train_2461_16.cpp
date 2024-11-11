#include <bits/stdc++.h>
using namespace std;
const int N = 705, P = 1000000007;
using ll = long long;
char s[N];
int n, a[N];
template <typename T>
inline void add(T &a, ll b) {
  a = (a + b) % P;
}
ll dp[N][N][10][2];
int main() {
  ios::sync_with_stdio(false);
  cin >> (s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] - 48;
  for (int i = 1; i < 10; i++) dp[0][0][i][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 1; k < 10; k++)
        for (int l = 0; l < 2; l++)
          for (int c = 0; c <= (l ? 9 : a[i + 1]); c++)
            add(dp[i + 1][j + (c >= k)][k][l | (c < a[i + 1])], dp[i][j][k][l]);
  ll ans = 0;
  for (int k = 1; k < 10; k++) {
    ll cur = 1;
    for (int i = 1; i <= n; i++, cur = cur * 10 + 1 % P)
      add(ans, (dp[n][i][k][0] + dp[n][i][k][1]) * cur % P);
  }
  cout << ans << endl;
  return 0;
}
