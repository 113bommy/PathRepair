#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 10;
long long lowbit(long long x) { return x & -x; }
bool ispow(long long n) { return (n & (n - 1)) == 0; }
long long fast(long long a, long long n) {
  long long base = a, res = 1;
  while (n) {
    if (n & 1) res = ((res % mod) * (base % mod)) % mod;
    base = ((base % mod) * (base % mod)) % mod;
    n >>= 1;
  }
  return res % mod;
}
long long las[maxn];
string txt = "wygbro";
long long dp[maxn];
bool s[1030][1030][4];
bool vis[1030][1030];
long long ans[maxn], cnt;
long long dx[] = {-1, 0, 1, 0};
long long dy[] = {0, 1, 0, -1};
long long dfs(long long x, long long y) {
  long long Size = 1;
  vis[x][y] = true;
  long long res = Size;
  for (long long i = 0; i < 4; i++) {
    long long vx = x + dx[i], vy = y + dy[i];
    if (s[x][y][i] && vis[vx][vy] == 0) {
      res += dfs(vx, vy);
    }
  }
  return res;
}
long long cmp(long long a, long long b) { return a > b; }
signed main() {
  long long n, m;
  cin >> n >> m;
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (1); j <= (m); ++j) {
      long long a;
      scanf("%lld", &a);
      long long wall = 3;
      while (wall != -1) {
        if (a == 0 || a % 2 == 0)
          s[i][j][wall] = true;
        else if (a % 2 == 1)
          s[i][j][wall] = false;
        wall--;
        a /= 2;
      }
    }
  }
  for (long long i = (1); i <= (n); ++i) {
    for (long long j = (1); j <= (m); ++j) {
      if (vis[i][j] == 0) {
        ans[cnt++] = dfs(i, j);
      }
    }
  }
  sort(ans, ans + cnt, cmp);
  for (long long i = 0; i < cnt; i++) cout << ans[i] << ' ';
  return 0;
}
