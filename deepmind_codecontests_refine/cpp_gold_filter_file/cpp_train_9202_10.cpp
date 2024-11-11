#include <bits/stdc++.h>
using namespace std;
long long ans;
const int maxn = 11000;
const int mod = 1000000007;
char s[3][maxn];
long long dp[2][1 << 3];
bool flag[4];
int n;
int x, y;
const int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool build(int dir) {
  int dx = x, dy = y;
  for (int i = 1; i <= 2; ++i) {
    dx += d[dir][0], dy += d[dir][1];
    if (!(dx >= 0 && dx < 3 && dy >= 0 && dy < n) || s[dx][dy] == 'X') return 0;
  }
  dx = x, dy = y;
  for (int i = 0; i <= 2; ++i) {
    s[dx][dy] = 'X';
    dx += d[dir][0], dy += d[dir][1];
  }
  return 1;
}
void reset(int dir) {
  int dx = x, dy = y;
  for (int i = 0; i <= 2; ++i) {
    s[dx][dy] = '.';
    dx += d[dir][0], dy += d[dir][1];
  }
}
int cur;
inline void update(int a, int b) {
  if (b & 8) (dp[cur][b ^ 8] += dp[cur ^ 1][a]) %= mod;
}
long long cal() {
  cur = 0;
  memset(dp, 0, sizeof(dp));
  dp[cur][7] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 3; ++j) {
      cur ^= 1;
      memset(dp[cur], 0, sizeof(dp[cur]));
      if (s[j][i] == 'X')
        for (int k = 0; k < 8; ++k) {
          if (k & 1)
            dp[cur][k] = dp[cur ^ 1][(k >> 1) + 4];
          else
            dp[cur][k] = 0;
        }
      else
        for (int k = 0; k < 8; ++k) {
          update(k, k << 1);
          if (i && !(k & 4)) update(k, (k << 1) ^ 8 ^ 1);
          if (j && !(k & 1)) update(k, (k << 1) ^ 3);
        }
    }
  return dp[cur][7];
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 3; ++i) scanf("%s", s[i]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 3; ++j)
      if (s[j][i] == 'O') x = j, y = i;
  for (int i = 0; i < 4; ++i) flag[i] = 0;
  ans = 0;
  for (int i = 0; i < 4; ++i) {
    if (build(i)) {
      flag[i] = 1;
      ans = (ans + cal()) % mod;
      reset(i);
    }
  }
  for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j) {
      if (flag[i] && flag[j]) {
        build(i), build(j);
        ans = (ans - cal() + mod) % mod;
        reset(i), reset(j);
      }
    }
  for (int i = 0; i < 4; ++i)
    for (int j = i + 1; j < 4; ++j)
      for (int k = j + 1; k < 4; ++k) {
        if (flag[i] && flag[j] && flag[k]) {
          build(i), build(j), build(k);
          ans = (ans + cal()) % mod;
          reset(i), reset(j), reset(k);
        }
      }
  cout << ans << endl;
}
