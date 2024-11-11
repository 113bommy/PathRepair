#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int Mod = 1000000007;
struct node {
  int x, y, t;
  node(int a, int b, int c) {
    x = a;
    y = b;
    t = c;
  }
};
long long c[maxn][maxn];
long long dp[maxn][maxn][2];
int d[maxn][maxn][2];
int n, m, p, k;
void init() {
  memset(c, 0, sizeof(c));
  for (int i = 0; i < maxn; i++) c[i][0] = 1;
  for (int i = 1; i < maxn; i++) {
    for (int j = 1; j < maxn; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
  }
}
void bfs() {
  queue<node> q;
  memset(d, -1, sizeof(d));
  memset(dp, 0, sizeof(dp));
  dp[n][m][0] = 1;
  q.push(node(n, m, 0));
  d[n][m][0] = 0;
  while (!q.empty()) {
    int a = q.front().x, b = q.front().y, t = q.front().t;
    int step = d[a][b][t];
    q.pop();
    if (t == 0) {
      for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
          if (i + j == 0 || i * 50 + j * 100 > k) continue;
          int x = n - a + i, y = m - b + j;
          if (d[x][y][1] == -1) {
            d[x][y][1] = step + 1;
            dp[x][y][1] = dp[a][b][0] * c[a][i] * c[b][j] % Mod;
            q.push(node(x, y, 1));
          } else if (step + 1 == d[x][y][1]) {
            dp[x][y][1] = (dp[x][y][1] + dp[a][b][0] * c[a][i] * c[b][j]) % Mod;
          }
        }
      }
    } else if (t == 1) {
      for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
          if (i + j == 0 || i * 50 + j * 100 > k) continue;
          int x = n - a + i, y = m - b + j;
          if (d[x][y][0] == -1) {
            d[x][y][0] = step + 1;
            dp[x][y][0] = dp[a][b][1] * c[a][i] * c[b][j] % Mod;
            q.push(node(x, y, 0));
          } else if (step + 1 == d[x][y][1]) {
            dp[x][y][0] = (dp[x][y][0] + dp[a][b][1] * c[a][i] * c[b][j]) % Mod;
          }
        }
      }
    }
  }
  cout << d[n][m][1] << endl << dp[n][m][1] << endl;
}
int main() {
  init();
  while (scanf("%d%d", &p, &k) != EOF) {
    n = m = 0;
    for (int i = 1; i <= p; i++) {
      int x;
      scanf("%d", &x);
      if (x == 50)
        n++;
      else
        m++;
    }
    bfs();
  }
  return 0;
}
