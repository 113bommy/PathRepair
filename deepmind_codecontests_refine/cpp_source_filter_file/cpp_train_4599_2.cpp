#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
int N, T;
vector<int> num[3];
int ways[52][52][52][3];
int dp[52][52][52 * 52], dp1[52][52 * 52];
long long fact[52], ifact[52];
long long ans;
long long expo(long long a, long long e) {
  if (e == 0) return 1;
  if (e & 1) return expo(a * a % 1000000007, e >> 1) * a % 1000000007;
  return expo(a * a % 1000000007, e >> 1);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> T;
  fact[0] = 1;
  for (auto i = (1); i < (N + 1); i++) {
    fact[i] = fact[i - 1] * i % 1000000007;
  }
  ifact[N] = expo(fact[N], 1000000007 - 2);
  for (auto i = (N)-1; i >= (0); i--) {
    ifact[i] = ifact[i + 1] * (i + 1) % 1000000007;
  }
  for (auto i = (0); i < (N); i++) {
    int x, y;
    cin >> x >> y;
    y--;
    num[y].push_back(x);
  }
  for (auto i = (0); i < (3); i++) {
    sort((num[i]).begin(), (num[i]).end());
  }
  for (auto i = (0); i < (((int)((num[0]).size())) + 1); i++) {
    for (auto j = (0); j < (((int)((num[1]).size())) + 1); j++) {
      for (auto k = (0); k < (((int)((num[2]).size())) + 1); k++) {
        if (i + j + k == 0) continue;
        if (i + j + k == 1) {
          if (i == 1) {
            ways[i][j][k][0] = 1;
          }
          if (j == 1) {
            ways[i][j][k][1] = 1;
          }
          if (k == 1) {
            ways[i][j][k][2] = 1;
          }
          continue;
        }
        for (auto m = (0); m < (3); m++) {
          if (i && m != 0) {
            ways[i][j][k][0] += ways[i - 1][j][k][m];
            if (ways[i][j][k][0] >= 1000000007) ways[i][j][k][0] -= 1000000007;
          }
          if (j && m != 1) {
            ways[i][j][k][1] += ways[i][j - 1][k][m];
            if (ways[i][j][k][1] >= 1000000007) ways[i][j][k][1] -= 1000000007;
          }
          if (k && m != 2) {
            ways[i][j][k][2] += ways[i][j][k - 1][m];
            if (ways[i][j][k][2] >= 1000000007) ways[i][j][k][2] -= 1000000007;
          }
        }
      }
    }
  }
  dp[0][0][0] = 1;
  for (auto i = (0); i < (((int)((num[0]).size()))); i++) {
    int x = num[0][i];
    for (auto j = (i + 1) - 1; j >= (0); j--) {
      for (auto k = (T + 1 - x) - 1; k >= (0); k--) {
        dp[j + 1][0][k + x] += dp[j][0][k];
        if (dp[j + 1][0][k + x] >= 1000000007)
          dp[j + 1][0][k + x] -= 1000000007;
      }
    }
  }
  for (auto i = (0); i < (((int)((num[1]).size()))); i++) {
    int x = num[1][i];
    for (auto j = (i + 1) - 1; j >= (0); j--) {
      for (auto k = (T + 1 - x) - 1; k >= (0); k--) {
        for (auto m = (0); m < (((int)((num[0]).size())) + 1); m++) {
          dp[m][j + 1][k + x] += dp[m][j][k];
          if (dp[m][j + 1][k + x] >= 1000000007)
            dp[m][j + 1][k + x] -= 1000000007;
        }
      }
    }
  }
  dp1[0][0] = 1;
  for (auto i = (0); i < (((int)((num[2]).size()))); i++) {
    int x = num[2][i];
    for (auto j = (i + 1) - 1; j >= (0); j--) {
      for (auto k = (T + 1 - x) - 1; k >= (0); k--) {
        dp1[j + 1][k + x] += dp1[j][k];
        if (dp1[j + 1][k + x] >= 1000000007) dp1[j + 1][k + x] -= 1000000007;
      }
    }
  }
  for (auto i = (0); i < (((int)((num[0]).size())) + 1); i++) {
    for (auto j = (0); j < (((int)((num[1]).size())) + 1); j++) {
      for (auto k = (0); k < (((int)((num[2]).size())) + 1); k++) {
        long long num =
            0ll + ways[i][j][k][0] + ways[i][j][k][1] + ways[i][j][k][2];
        num *= fact[i];
        num %= 1000000007;
        num *= fact[j];
        num %= 1000000007;
        num *= fact[k];
        num %= 1000000007;
        for (auto m = (0); m < (T + 1); m++) {
          ans += dp[i][j][m] * dp1[k][T - m] % 1000000007 * num;
          ans %= 1000000007;
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
