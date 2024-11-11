#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int m, d;
long long dp[2002][2002][2];
bool good(vector<int> a) {
  int n = (int)a.size() - 1;
  int M = 0;
  for (int i = 1; i <= n; ++i) {
    M = (M * 10 + a[i]) % m;
    if (i % 2 == 0 && a[i] != d) {
      return false;
    }
    if (i % 2 == 1 && a[i] == d) {
      return false;
    }
  }
  return M == 0;
}
void upd() {
  for (int i = 1; i <= 2000; ++i) {
    for (int j = 0; j <= 2000; ++j) {
      dp[i][j][0] = 0;
      dp[i][j][1] = 0;
    }
  }
}
long long f(vector<int> a) {
  int n = (int)a.size() - 1;
  for (int j = 0; j < a[1]; ++j) {
    if (j != d) {
      dp[1][j % m][0] += 1;
    }
  }
  if (a[1] != d) {
    dp[1][a[1] % m][1] = 1;
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i % 2 == 1) {
        int nj = (j * 10 + d) % m;
        if (a[i + 1] == d) {
          dp[i + 1][nj][1] += dp[i][j][1];
          dp[i + 1][nj][1] %= mod;
        } else if (d < a[i + 1]) {
          dp[i + 1][nj][0] += dp[i][j][1];
          dp[i + 1][nj][0] %= mod;
        }
        dp[i + 1][nj][0] += dp[i][j][0];
        dp[i + 1][nj][0] %= mod;
      } else {
        for (int now = 0; now <= 9; ++now) {
          if (now != d) {
            int nj = (j * 10 + now) % m;
            if (now == a[i + 1]) {
              dp[i + 1][nj][1] += dp[i][j][1];
              dp[i + 1][nj][1] %= mod;
            } else if (now < a[i + 1]) {
              dp[i + 1][nj][0] += dp[i][j][1];
              dp[i + 1][nj][0] %= mod;
            }
            dp[i + 1][nj][0] += dp[i][j][0];
            dp[i + 1][nj][0] %= mod;
          }
        }
      }
    }
  }
  long long ans = dp[n][0][0] + dp[n][0][1];
  upd();
  return ans;
}
int main() {
  scanf("%d %d", &m, &d);
  string A, B;
  cin >> A;
  cin >> B;
  vector<int> a, b;
  a.push_back(0);
  b.push_back(0);
  for (int i = 0; i < (int)A.size(); ++i) {
    a.push_back(A[i] - '0');
  }
  for (int i = 0; i < (int)B.size(); ++i) {
    b.push_back(B[i] - '0');
  }
  cout << (f(b) - f(a) + good(a) + mod) % mod << endl;
  return 0;
}
