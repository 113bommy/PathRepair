#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 1e3 + 10;
const int maxM = 1e6 + 10;
const int inf = 0x3f3f3f3f;
struct pos {
  int x2, y2;
  int x5, y5;
};
int N, tag = 0;
int G[maxn][maxn];
int cnt[maxn][maxn][2];
pos from[maxn][maxn];
int dp[maxn][maxn][2];
char ans0[2 * maxn];
int tail;
int div2(int x) {
  int ans = 0;
  while (x && x % 2 == 0) {
    x /= 2;
    ans++;
  }
  return ans;
}
int div5(int x) {
  int ans = 0;
  while (x && x % 5 == 0) {
    x /= 5;
    ans++;
  }
  return ans;
}
void out0(int x, int y) {
  for (int i = 1; i < x; i++) ans0[++tail] = 'D';
  for (int i = 1; i < N; i++) ans0[++tail] = 'R';
  for (int i = x; i < N; i++) ans0[++tail] = 'D';
}
void dfs2(int x, int y) {
  if (x <= 1 && y <= 1) return;
  dfs2(from[x][y].x2, from[x][y].y2);
  if (from[x][y].x2 == x - 1 && from[x][y].y2 == y) {
    cout << 'D';
  } else {
    cout << 'R';
  }
}
void dfs5(int x, int y) {
  if (x <= 1 && y <= 1) return;
  dfs5(from[x][y].x5, from[x][y].y5);
  if (from[x][y].x5 == x - 1 && from[x][y].y5 == y) {
    cout << 'D';
  } else {
    cout << 'R';
  }
}
void solve() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int(&cur)[2] = dp[i][j];
      int(&up)[2] = dp[i - 1][j];
      int(&left)[2] = dp[i][j - 1];
      int(&coun)[2] = cnt[i][j];
      if ((j == 1) || (i != 1 && up[0] < left[0])) {
        cur[0] = up[0] + coun[0];
        from[i][j].x2 = i - 1;
        from[i][j].y2 = j;
      } else {
        cur[0] = left[0] + coun[0];
        from[i][j].x2 = i;
        from[i][j].y2 = j - 1;
      }
      if ((j == 1) || (i != 1 && up[1] < left[1])) {
        cur[1] = up[1] + coun[1];
        from[i][j].x5 = i - 1;
        from[i][j].y5 = j;
      } else {
        cur[1] = left[1] + coun[1];
        from[i][j].x5 = i;
        from[i][j].y5 = j - 1;
      }
    }
  }
  if (tail && dp[N][N][0] >= 1 && dp[N][N][1] >= 1) {
    cout << 1 << '\n';
    for (int i = 1; i <= tail; i++) cout << ans0[i];
  } else if (dp[N][N][0] < dp[N][N][1]) {
    cout << dp[N][N][0] << '\n';
    dfs2(N, N);
  } else {
    cout << dp[N][N][1] << '\n';
    dfs5(N, N);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> G[i][j];
      if (G[i][j] == 0) {
        out0(i, j);
        G[i][j] = 10;
      }
      cnt[i][j][0] = div2(G[i][j]);
      cnt[i][j][1] = div5(G[i][j]);
    }
  }
  solve();
  return 0;
}
