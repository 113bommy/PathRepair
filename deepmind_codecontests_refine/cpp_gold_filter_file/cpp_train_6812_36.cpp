#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long powm(long long base, long long exp, long long mod = 1000000007) {
  base %= mod;
  long long ans = 1;
  while (exp) {
    if (exp & 1LL) ans = (ans * base) % mod;
    exp >>= 1LL, base = (base * base) % mod;
  }
  return ans;
}
string s[101];
long long dp[101][101][11];
char mv[101][101][11];
long long n, m, k;
bool check(int i, int j) { return (i < n && i >= 0 && j < m && j >= 0); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  k++;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
  }
  long long ans = -1;
  int x = n, y = m, r = 0;
  for (long long i = n - 1; i >= 0; i--) {
    for (long long j = m - 1; j >= 0; j--) {
      for (long long d = 0; d < k; d++) {
        dp[i][j][d] = -1;
        if (check(i + 1, j - 1) &&
            dp[i + 1][j - 1][(10 * k + d - (s[i][j] - '0')) % k] != -1) {
          dp[i][j][d] = (s[i][j] - '0') +
                        dp[i + 1][j - 1][(10 * k + d - (s[i][j] - '0')) % k];
          mv[i][j][d] = 'R';
        }
        if (check(i + 1, j + 1) &&
            dp[i + 1][j + 1][(10 * k + d - (s[i][j] - '0')) % k] != -1) {
          if (dp[i][j][d] <
              (s[i][j] - '0') +
                  dp[i + 1][j + 1][(10 * k + d - (s[i][j] - '0')) % k]) {
            dp[i][j][d] = (s[i][j] - '0') +
                          dp[i + 1][j + 1][(10 * k + d - (s[i][j] - '0')) % k];
            mv[i][j][d] = 'L';
          }
        }
      }
      if (i == n - 1) {
        dp[i][j][(s[i][j] - '0') % k] = s[i][j] - '0';
        continue;
      }
      if (i == 0 && ans < dp[i][j][0]) {
        ans = dp[i][j][0];
        x = i;
        y = j;
      }
    }
  }
  cout << ans << '\n';
  if (ans == -1) return 0;
  stack<char> t;
  while (x < n - 1) {
    if (mv[x][y][r] == 'L') {
      t.push('L');
      r = (10 * k + r - (s[x][y] - '0')) % k;
      y++;
    } else {
      t.push('R');
      r = (10 * k + r - (s[x][y] - '0')) % k;
      y--;
    }
    x++;
  }
  cout << y + 1 << '\n';
  while (!t.empty()) {
    char c = t.top();
    cout << c;
    t.pop();
  }
}
