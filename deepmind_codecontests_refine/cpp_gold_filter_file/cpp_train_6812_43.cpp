#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
string stat[110][110][12];
long long dp[110][110][12];
long long A[110][110];
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<vector<char> > s(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      A[i][j] = s[i][j] - '0';
    }
  }
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int z = 0; z < k + 1; z++) {
        stat[i][j][z] = "";
      }
    }
  }
  for (int j = 0; j < m; j++) {
    dp[n - 1][j][A[n - 1][j] % (k + 1)] = A[n - 1][j];
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < m; j++) {
      for (int z = 0; z < k + 1; z++) {
        if (dp[i][j][z] >= 0) {
          if (j >= 1) {
            long long val = z + A[i - 1][j - 1];
            val = val % (k + 1);
            if (dp[i - 1][j - 1][val] < dp[i][j][z] + A[i - 1][j - 1]) {
              dp[i - 1][j - 1][val] = dp[i][j][z] + A[i - 1][j - 1];
              stat[i - 1][j - 1][val] = stat[i][j][z] + 'L';
            }
          }
          if (j < m - 1) {
            long long val = z + A[i - 1][j + 1];
            val = val % (k + 1);
            if (dp[i - 1][j + 1][val] < dp[i][j][z] + A[i - 1][j + 1]) {
              dp[i - 1][j + 1][val] = dp[i][j][z] + A[i - 1][j + 1];
              stat[i - 1][j + 1][val] = stat[i][j][z] + 'R';
            }
          }
        }
      }
    }
  }
  long long ans = -1;
  long long ind = -1;
  for (int j = 0; j < m; j++) {
    if (dp[0][j][0] > ans) {
      ans = dp[0][j][0];
      ind = j;
    }
  }
  if (ans == -1) {
    cout << ans;
    return;
  }
  cout << ans << "\n";
  string s1 = stat[0][ind][0];
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == 'R') {
      ind--;
    } else {
      ind++;
    }
  }
  cout << ind + 1 << "\n";
  cout << s1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}
