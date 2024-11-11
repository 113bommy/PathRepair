#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "Yes" : "No");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
int c[5005], d[5005], B;
vector<int> mp[5005];
int dp[5005][5005][2];
int sz[5005];
void mm(int &x, int y) { x = min(x, y); }
void dfs(int x) {
  sz[x] = 1;
  dp[x][0][0] = 0;
  dp[x][1][0] = c[x];
  dp[x][1][1] = c[x] - d[x];
  for (int c : mp[x]) {
    dfs(c);
    for (int j = sz[x]; ~j; j--) {
      for (int k = 0; k <= sz[c]; k++) {
        mm(dp[x][j + k][0], dp[x][j][0] + dp[c][k][0]);
        mm(dp[x][j + k][1], dp[x][j][1] + dp[c][k][0]);
        mm(dp[x][j + k][1], dp[x][j][1] + dp[c][k][1]);
      }
    }
    sz[x] += sz[c];
  }
}
void fmain(int tid) {
  scanf("%d%d", &n, &B);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    scanf("%d%d", c + i, d + i);
    if (i > 1) {
      int fa;
      scanf("%d", &fa);
      mp[fa].push_back(i);
    }
  }
  for (int(i) = 0; (i) < (int)(n + 1); (i)++)
    for (int(j) = 0; (j) < (int)(n + 1); (j)++)
      for (int(z) = 0; (z) < (int)(2); (z)++) dp[i][j][z] = (1000000000) + 5;
  dfs(1);
  int ans = n;
  while (dp[1][ans][0] > B && dp[1][ans][1] > B) ans--;
  printf("%d\n", ans);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
