#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, ans;
long long sum;
char str[maxn];
int f[maxn][10], g[10][10], s[maxn], vis[maxn], dp[8][260], v[8][8][260][260],
    state[maxn];
vector<int> p[10];
vector<int>::iterator it;
queue<int> q;
int main() {
  scanf("%d%s", &n, str);
  int i, j, u, a, b, c;
  for (i = 1; i <= n; i++) s[i] = str[i - 1] - 'a', p[s[i]].push_back(i);
  memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g));
  for (i = 0; i < 8; i++) {
    g[i][i] = 0, vis[n + i + 1] = 1;
    memset(vis, 0, sizeof(vis));
    for (it = p[i].begin(); it != p[i].end(); it++)
      q.push(*it), f[*it][i] = 0, vis[*it] = 1;
    while (!q.empty()) {
      u = q.front(), q.pop();
      if (u != 1 && !vis[u - 1])
        q.push(u - 1), vis[u - 1] = 1, f[u - 1][i] = f[u][i] + 1;
      if (u != n && !vis[u + 1])
        q.push(u + 1), vis[u + 1] = 1, f[u + 1][i] = f[u][i] + 1;
      if (!vis[n + s[u] + 1]) {
        vis[n + s[u] + 1] = 1, g[s[u]][i] = f[u][i];
        for (it = p[s[u]].begin(); it != p[s[u]].end(); it++)
          if (!vis[*it]) q.push(*it), f[*it][i] = f[u][i] + 1, vis[*it] = 1;
      }
    }
  }
  memset(v, 0x3f, sizeof(v));
  for (a = 0; a < 8; a++)
    for (b = 0; b <= a; b++) {
      for (i = 0; i < 256; i++)
        for (j = 0; j < 256; j++) {
          for (c = 0; c < 8; c++)
            v[a][b][i][j] =
                min(v[a][b][i][j],
                    g[a][c] + g[b][c] + ((i >> c) & 1) + ((j >> c) & 1) + 1);
          v[b][a][j][i] = v[a][b][i][j];
        }
    }
  for (i = 1; i <= n; i++) {
    for (j = max(1, i - 15); j < i; j++) {
      int tmp = i - j;
      for (c = 0; c < 8; c++) tmp = min(tmp, f[i][c] + f[j][c] + 1);
      if (ans < tmp) ans = tmp, sum = 0;
      if (ans == tmp) sum++;
    }
    for (a = 0; a < 8; a++) state[i] |= (f[i][a] - g[s[i]][a]) << a;
    for (a = 0; a < 8; a++)
      for (j = 0; j < 256; j++)
        if (dp[a][j]) {
          int tmp = v[a][s[i]][j][state[i]];
          if (ans < tmp) ans = tmp, sum = 0;
          if (ans == tmp) sum += dp[a][j];
        }
    if (i > 15) dp[s[i - 15]][state[i - 15]]++;
  }
  printf("%d %lld\n", ans, sum);
  return 0;
}
