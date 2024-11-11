#include <bits/stdc++.h>
using namespace std;
string s[5];
long long ba[2010][2], h[2010][3][2][2], ni[2010][2], n, m, dp[2010][2][2010];
long long po(long long x, long long y, long long m1) {
  long long z = 1;
  while (y) {
    if (y % 2) z = z * x % m1;
    x = x * x % m1;
    y /= 2;
  }
  return z;
}
void init() {
  ba[0][0] = ba[0][1] = 1;
  for (int i = 1; i <= 2000; i++)
    ba[i][0] = ba[i - 1][0] * 31 % 99999941,
    ba[i][1] = ba[i - 1][1] * 37 % 998244353;
  ni[0][0] = ni[0][1] = 1;
  for (int i = 1; i <= 2000; i++)
    ni[i][0] = ni[i - 1][0] * po(31, 99999941 - 2, 99999941) % 99999941,
    ni[i][1] = ni[i - 1][1] * po(37, 998244353 - 2, 998244353) % 998244353;
  for (int i = 0; i <= 2; i++) {
    for (int j = 1; j <= s[i].length(); j++)
      h[j][i][0][0] =
          (h[j - 1][i][0][0] + (s[i][j - 1] - 'a') * ba[j - 1][0]) % 99999941,
      h[j][i][1][0] =
          (h[j - 1][i][1][0] + (s[i][j - 1] - 'a') * ba[j - 1][1]) % 998244353;
    for (int j = s[i].length(); j >= 1; j--)
      h[j][i][0][1] =
          (h[j + 1][i][0][1] + (s[i][j - 1] - 'a') * ba[s[i].length() - j][0]) %
          99999941,
      h[j][i][1][1] =
          (h[j + 1][i][1][1] + (s[i][j - 1] - 'a') * ba[s[i].length() - j][1]) %
          998244353;
  }
}
long long que1(int x, int y, int l, int r) {
  int z;
  if (x == 2)
    z = m;
  else
    z = n;
  if (y)
    return (h[l][x][0][y] - h[r + 1][x][0][y] + 99999941) * ni[z - r][0] %
           99999941;
  else
    return (h[r][x][0][y] - h[l - 1][x][0][y] + 99999941) * ni[l - 1][0] %
           99999941;
}
long long que2(int x, int y, int l, int r) {
  int z;
  if (x == 2)
    z = m;
  else
    z = n;
  if (y)
    return (h[l][x][1][y] - h[r + 1][x][1][y] + 998244353) * ni[z - r][1] %
           998244353;
  else
    return (h[r][x][1][y] - h[l - 1][x][1][y] + 998244353) * ni[l - 1][1] %
           998244353;
}
bool ch(int x, int y, int l, int r, int p, int q, int a, int b) {
  return (que1(x, y, l, r) == que1(p, q, a, b) &&
          que2(x, y, l, r) == que2(p, q, a, b));
}
long long work1() {
  init();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      if (m % 2 == 0 && i >= m / 2 &&
          ch(2, 1, 1, m / 2, j, 0, i - m / 2 + 1, i) &&
          ch(2, 0, m / 2 + 1, m, j ^ 1, 0, i - m / 2 + 1, i))
        ans++;
      if (m % 2 == 0 && m > 2 && i + (m / 2) - 1 <= n &&
          ch(2, 0, 1, m / 2, j, 0, i, i + m / 2 - 1) &&
          ch(2, 1, m / 2 + 1, m, j ^ 1, 0, i, i + m / 2 - 1))
        ans++;
      if (m == 1 && s[j][i - 1] == s[2][0]) ans++;
    }
  }
  return ans;
}
void add(long long &x, long long y) { x = (x + y) % 1000000007; }
long long work2(int x) {
  if (x) reverse(s[2].begin(), s[2].end());
  init();
  memset(dp, 0, sizeof(dp));
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 1; k < m; k++) {
        if (k == 1 && s[j][i - 1] == s[2][k - 1]) add(dp[i][j][k], 1);
        if (k % 2 == 0 && i >= (k / 2) &&
            ch(2, 1, 1, k / 2, j ^ 1, 0, i - k / 2 + 1, i) &&
            ch(2, 0, k / 2 + 1, k, j, 0, i - k / 2 + 1, i))
          add(dp[i][j][k], 1);
        if (k > 1 && s[2][k - 1] == s[j][i - 1])
          add(dp[i][j][k], dp[i - 1][j][k - 1]);
        if (k > 2 && s[2][k - 1] == s[j][i - 1] &&
            s[2][k - 2] == s[j ^ 1][i - 1])
          add(dp[i][j][k], dp[i - 1][j ^ 1][k - 2]);
        if ((m - k) % 2 == 0 && i + (m - k) / 2 - 1 <= n &&
            ch(2, 0, k + 1, (m + k) / 2, j, 0, i, i + (m - k) / 2 - 1) &&
            ch(2, 1, (m + k) / 2, m, j ^ 1, 0, i, i + (m - k) / 2 - 1))
          add(ans, dp[i - 1][j][k]);
        if (k == m - 1 && s[2][k] == s[j][i - 1]) add(ans, dp[i - 1][j][k]);
      }
    }
  }
  if (x) reverse(s[2].begin(), s[2].end());
  return ans;
}
int main() {
  cin >> s[0] >> s[1] >> s[2];
  n = s[0].length();
  m = s[2].length();
  cout << (work1() + work2(0) + work2(1)) % 1000000007 << endl;
  return 0;
}
