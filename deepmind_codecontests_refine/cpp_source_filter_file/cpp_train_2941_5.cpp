#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long p = 1, data = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + (ch ^ 48);
    ch = getchar();
  }
  return p * data;
}
inline long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = a * r;
    a = a * a;
    b >>= 1;
  }
  return r;
}
inline long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}
const int mod = 1e9 + 7, maxn = 1e3 + 5;
char mp[maxn][maxn];
int dp[maxn][maxn], dir[4][2] = {1, 0, 0, 1, 0, -1, -1, 0};
int main() {
  memset(dp, 0x3f3f3f3f, sizeof(dp));
  int n = read(), m = read(), Q = read();
  for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
  queue<pair<int, int> > q;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (i - 1 >= 1 && i <= n && mp[i][j] == mp[i - 1][j]) {
        if (dp[i][j]) q.push(make_pair(i, j));
        if (dp[i - 1][j]) q.push(make_pair(i - 1, j));
        dp[i][j] = dp[i - 1][j] = 0;
      }
      if (j - 1 >= 1 && j <= m && mp[i][j] == mp[i][j - 1]) {
        if (dp[i][j]) q.push(make_pair(i, j));
        if (dp[i][j - 1]) q.push(make_pair(i, j - 1));
        dp[i][j] = dp[i][j - 1] = 0;
      }
    }
  while (!q.empty()) {
    pair<int, int> t = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = t.first + dir[i][0], y = t.second + dir[i][1];
      if (x >= 1 && y >= 1 && x <= n && y <= m &&
          dp[t.first][t.second] + 1 < dp[x][y]) {
        dp[x][y] = dp[t.first][t.second] + 1;
        q.push(make_pair(x, y));
      }
    }
  }
  while (Q--) {
    int i = read(), j = read(), p = read();
    if (p <= dp[i][j] || dp[i][j] == 0x3f3f3f3f)
      printf("%c\n", mp[i][j]);
    else
      printf("%d\n", ((p - dp[i][j]) % 2 == 0) ? (mp[i][j] - '0')
                                               : (mp[i][j] - '0') ^ 1);
  }
  return 0;
}
