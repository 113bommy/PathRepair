#include <bits/stdc++.h>
using namespace std;
string a, b, s;
int n;
vector<vector<int> > dp, dp1, dp2;
vector<pair<int, int> > r[26];
int o[26][26];
int calc(int i, int j) {
  if (i == j) return dp[i][j] = 1 << s[i];
  int &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = 0;
  for (int k = i; k < j; ++k) {
    int a = calc(i, k);
    int b = calc(k + 1, j);
    for (int i = 0; i < 26; ++i)
      if ((a >> i) & 1)
        for (int j = 0; j < 26; ++j)
          if ((b >> j) & 1) ret |= o[i][j];
  }
  return ret;
}
int calc1(int i, int j) {
  if (i == a.size() && j == b.size()) return 0;
  int &ret = dp[i][j];
  if (ret != -1) return ret;
  ret = 128;
  for (int x = i; x < a.size(); ++x)
    for (int y = j; y < b.size(); ++y)
      if (dp1[i][x] & dp2[j][y]) ret = min(ret, 1 + calc1(x + 1, y + 1));
  return ret;
}
int main() {
  cin >> a >> b >> n;
  for (int i = 0; i < n; ++i) {
    char x, a, b;
    scanf(" %c->%c%c", &x, &a, &b);
    x -= 'a';
    a -= 'a';
    b -= 'a';
    o[a][b] |= 1 << x;
  }
  s = a;
  for (int i = 0; i < s.size(); ++i) s[i] -= 'a';
  dp = vector<vector<int> >(s.size(), vector<int>(s.size(), -1));
  for (int i = 0; i < s.size(); ++i)
    for (int j = i; j < s.size(); ++j) calc(i, j);
  dp1 = dp;
  s = b;
  for (int i = 0; i < s.size(); ++i) s[i] -= 'a';
  dp = vector<vector<int> >(s.size(), vector<int>(s.size(), -1));
  for (int i = 0; i < s.size(); ++i)
    for (int j = i; j < s.size(); ++j) calc(i, j);
  dp2 = dp;
  dp = vector<vector<int> >(a.size() + 1, vector<int>(b.size() + 1, -1));
  int ret = calc1(0, 0);
  if (ret > 64) ret = -1;
  printf("%d\n", ret);
  return 0;
}
