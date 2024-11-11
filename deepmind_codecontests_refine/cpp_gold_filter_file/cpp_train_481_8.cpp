#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> mat_mult(vector<vector<long long int>>& v1,
                                       vector<vector<long long int>>& v2) {
  vector<vector<long long int>> v3(4, vector<long long int>(4, 0));
  for (long long int i = 1; i <= 3; i++) {
    for (long long int j = 1; j <= 3; j++) {
      for (long long int k = 1; k <= 3; k++) {
        v3[i][j] += (v1[i][k] * v2[k][j]) % 1000000007ll;
        v3[i][j] %= 1000000007ll;
      }
    }
  }
  return v3;
}
vector<vector<long long int>> Power(vector<vector<long long int>>& a,
                                    long long int b) {
  if (b == 1) {
    return a;
  }
  vector<vector<long long int>> c = Power(a, b / 2);
  c = mat_mult(c, c);
  if (b % 2) {
    c = mat_mult(c, a);
  }
  return c;
}
long long int cur[4];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m;
  cin >> n >> m;
  vector<array<long long int, 3>> v;
  for (long long int i = 1; i <= n; i++) {
    long long int a, l, r;
    cin >> a >> l >> r;
    v.push_back({l, a, 1});
    v.push_back({r, a, -1});
  }
  sort(v.begin(), v.end());
  long long int prev_col = 1;
  vector<long long int> dp(4, 0);
  dp[2] = 1;
  for (long long int i = 0; i < v.size(); i++) {
    vector<vector<long long int>> f(4, vector<long long int>(4, 0));
    f[1][1] = 1;
    f[1][2] = 1;
    f[2][1] = 1;
    f[2][2] = 1;
    f[2][3] = 1;
    f[3][2] = 1;
    f[3][3] = 1;
    for (long long int j = 1; j <= 3; j++) {
      if (cur[j]) {
        f[j][1] = 0;
        f[j][2] = 0;
        f[j][3] = 0;
        f[1][j] = 0;
        f[2][j] = 0;
        f[3][j] = 0;
      }
    }
    if (v[i][0] - prev_col >= 1) {
      vector<vector<long long int>> mf = Power(f, v[i][0] - prev_col);
      long long int a = (dp[1] * mf[1][1]) % 1000000007ll +
                        (dp[2] * mf[1][2]) % 1000000007ll +
                        (dp[3] * mf[1][3]) % 1000000007ll;
      long long int b = (dp[1] * mf[2][1]) % 1000000007ll +
                        (dp[2] * mf[2][2]) % 1000000007ll +
                        (dp[3] * mf[2][3]) % 1000000007ll;
      long long int c = (dp[1] * mf[3][1]) % 1000000007ll +
                        (dp[2] * mf[3][2]) % 1000000007ll +
                        (dp[3] * mf[3][3]) % 1000000007ll;
      dp[1] = a % 1000000007ll;
      dp[2] = b % 1000000007ll;
      dp[3] = c % 1000000007ll;
    }
    cur[v[i][1]] += v[i][2];
    prev_col = v[i][0];
    for (long long int j = 1; j <= 3; j++) {
      if (cur[j]) {
        dp[j] = 0;
      }
    }
    prev_col = v[i][0];
  }
  vector<vector<long long int>> f(4, vector<long long int>(4, 0));
  f[1][1] = 1;
  f[1][2] = 1;
  f[2][1] = 1;
  f[2][2] = 1;
  f[2][3] = 1;
  f[3][2] = 1;
  f[3][3] = 1;
  for (long long int j = 1; j <= 3; j++) {
    if (cur[j]) {
      f[j][1] = 0;
      f[j][2] = 0;
      f[j][3] = 0;
      f[1][j] = 0;
      f[2][j] = 0;
      f[3][j] = 0;
    }
  }
  if (m - prev_col >= 1) {
    vector<vector<long long int>> mf = Power(f, m - prev_col);
    long long int a = (dp[1] * mf[1][1]) % 1000000007ll +
                      (dp[2] * mf[1][2]) % 1000000007ll +
                      (dp[3] * mf[1][3]) % 1000000007ll;
    long long int b = (dp[1] * mf[2][1]) % 1000000007ll +
                      (dp[2] * mf[2][2]) % 1000000007ll +
                      (dp[3] * mf[2][3]) % 1000000007ll;
    long long int c = (dp[1] * mf[3][1]) % 1000000007ll +
                      (dp[2] * mf[3][2]) % 1000000007ll +
                      (dp[3] * mf[3][3]) % 1000000007ll;
    dp[1] = a % 1000000007ll;
    dp[2] = b % 1000000007ll;
    dp[3] = c % 1000000007ll;
  }
  cout << dp[2] << "\n";
}
