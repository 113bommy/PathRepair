#include <bits/stdc++.h>
inline void cmin(int &x, int y) {
  if (y < x) x = y;
}
inline void cmax(int &x, int y) {
  if (y > x) x = y;
}
using namespace std;
const int N = 110;
char dp[N][N][28][2];
int n, m, u, v;
char s[10];
vector<pair<int, int> > e[N];
bool dfs(int u, int v, int k, int op) {
  if (dp[u][v][k][op] != 0x11) return dp[u][v][k][op];
  if (op == 0) {
    bool win = 0;
    for (auto p : e[u])
      if (p.second >= k) {
        win |= dfs(p.first, v, p.second, op ^ 1);
        if (win == 1) break;
      }
    return dp[u][v][k][op] = win;
  } else {
    bool win = 1;
    for (auto p : e[v])
      if (p.second >= k) {
        win &= dfs(u, p.first, p.second, op ^ 1);
        if (win == 0) break;
      }
    return dp[u][v][k][op] = win;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = (0); (i) <= (m - 1); ++i) {
    scanf("%d%d%s", &u, &v, s);
    --u;
    --v;
    e[u].push_back(make_pair(v, s[0] - 'a' + 1));
  }
  memset(dp, 0x11, sizeof(dp));
  for (int(i) = (0); (i) <= (n - 1); ++i) {
    for (int(j) = (0); (j) <= (n - 1); ++j)
      if (dfs(i, j, 0, 0))
        putchar('A');
      else
        putchar('B');
    puts("");
  }
}
