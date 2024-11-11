#include <bits/stdc++.h>
using namespace std;
const int N = 1000 * 2, mod = 1000 * 1000 * 1000 + 7;
long long n, dp[N + 10][N + 10], ans, k;
string s, s1;
void read();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) dp[i][1] = 1;
  for (int i = 1; i < k; i++) {
    for (int j = 1, tmp = j; j <= n; j++) {
      tmp = j;
      while (tmp <= n) {
        dp[tmp][i + 1] += dp[j][i];
        dp[tmp][i + 1] %= mod;
        tmp += j;
      }
    }
  }
  for (int i = 1; i <= n; i++) ans += dp[i][k];
  cout << ans % mod;
}
void read() { cin >> n; }
