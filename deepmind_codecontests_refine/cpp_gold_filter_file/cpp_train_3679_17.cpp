#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 1e6 + 10;
string s[101];
string x;
long long dp[101];
int n, m;
int fail[N];
struct matrix {
  long long v[4][4];
  matrix() {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) v[i][j] = 0;
  }
  matrix(long long u[4][4]) {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) v[i][j] = u[i][j];
  }
  matrix operator*(const matrix a) const {
    matrix ans;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++) {
          ans.v[i][j] += (v[i][k] * a.v[k][j]);
          ans.v[i][j] = (ans.v[i][j] + mod) % mod;
        }
    return ans;
  }
  void setunit() {
    for (int i = 0; i < 4; i++) v[i][i] = 1;
  }
};
long long mtx[4][4] = {
    {1, 2, -1, -1},
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
};
matrix calc(long long i) {
  matrix tmp(mtx);
  matrix ans;
  ans.setunit();
  while (i) {
    if (i & 1ll) ans = tmp * ans;
    tmp = tmp * tmp;
    i = i / 2ll;
  }
  return ans;
}
long long kmp(int p) {
  int m = x.length(), n = s[p].length();
  if (m > n) return 0;
  for (int i = 1, j = fail[0] = -1; i < m; i++) {
    while (j >= 0 && x[j + 1] != x[i]) j = fail[j];
    if (x[j + 1] == x[i]) j++;
    fail[i] = j;
  }
  int ans = 0;
  for (int i = 0, j = -1; i < n; i++) {
    while (j >= 0 && x[j + 1] != s[p][i]) j = fail[j];
    if (x[j + 1] == s[p][i]) j++;
    if (j == m - 1) {
      ans++;
      j = fail[j];
    }
  }
  return (long long)ans;
}
long long calc(int a, int b) {
  string p = s[a] + s[b];
  int s1 = s[a].length();
  int m = x.length(), n = p.length();
  if (m > n) return 0;
  for (int i = 1, j = fail[0] = -1; i < m; i++) {
    while (j >= 0 && x[j + 1] != x[i]) j = fail[j];
    if (x[j + 1] == x[i]) j++;
    fail[i] = j;
  }
  int ans = 0;
  for (int i = 0, j = -1; i < n; i++) {
    while (j >= 0 && x[j + 1] != p[i]) j = fail[j];
    if (x[j + 1] == p[i]) j++;
    if (j == m - 1) {
      if ((i - m + 1 < s1) && (i + 1) > s1) ans++;
      j = fail[j];
    }
  }
  return (long long)ans;
}
int main() {
  s[1] = "a";
  s[2] = "b";
  for (int i = 3; i <= 30; i++) s[i] = s[i - 1] + s[i - 2];
  cin >> n >> m;
  while (m--) {
    cin >> x;
    if (n <= 25) {
      cout << kmp(n) << endl;
      continue;
    }
    int len = x.length();
    int r = 1;
    while (s[r].length() < len) r++;
    long long add1 = calc(r, r), add2 = calc(r + 1, r);
    for (int i = 1; i <= r + 2; i++) dp[i] = kmp(i);
    dp[r + 3] = dp[r + 2] + dp[r + 1] + add1;
    dp[r + 4] = dp[r + 3] + dp[r + 2] + add2;
    dp[r + 5] = dp[r + 4] + dp[r + 3] + add1;
    dp[r + 6] = dp[r + 5] + dp[r + 4] + add2;
    if (n <= r + 6) {
      cout << dp[n] << endl;
      continue;
    }
    matrix mat = calc(n - r - 6);
    long long ans = 0;
    for (int i = 0; i < 4; i++) ans += mat.v[0][i] * dp[r + 6 - i];
    ans = ans % mod;
    while (ans < 0) ans += mod;
    cout << ans << endl;
  }
}
