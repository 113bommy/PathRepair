#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
long long w[N], sum[N][2];
vector<pair<int, long long> > g[N];
map<int, long long> m[N], ask[N];
int h[N], Next[N][22], Fa[N];
pair<int, long long> dp[N][22];
void dfs(int u, int fa) {
  Fa[u] = fa;
  long long tmp = w[u];
  for (auto t : g[u]) {
    if (t.first == fa) continue;
    dfs(t.first, u);
    if (sum[t.first][0] > 2 * t.second) {
      tmp += sum[t.first][0] - 2 * t.second;
    }
  }
  sum[u][0] = tmp;
  m[u][0] = tmp;
  for (auto t : g[u]) {
    if (sum[t.first][0] > 2 * t.second) {
      m[u][t.first] = tmp - (sum[t.first][0] - 2 * t.second);
    } else {
      m[u][t.first] = tmp;
    }
  }
}
void dfs1(int u, int fa, int favalue) {
  sum[u][1] = favalue;
  favalue += sum[u][0];
  for (auto t : g[u]) {
    if (t.first == fa) continue;
    long long tmp = favalue;
    if (sum[t.first][0] - 2 * t.second > 0) {
      tmp -= (sum[t.first][0] - 2 * t.second);
    }
    dfs1(t.first, u, max(tmp - 2 * t.second, 0LL));
  }
}
void dfs2(int u, int fa, int deep) {
  h[u] = deep;
  if (fa == -1) {
    Next[u][0] = u;
  }
  for (int i = 0; i < 22; i++) {
    if (fa == -1) continue;
    if (i == 0) {
      dp[u][i] = {fa, sum[u][0] + m[fa][u] + sum[fa][1] - ask[u][fa]};
      Next[u][i] = u;
    } else {
      int id = dp[u][i - 1].first;
      if (id == -1) continue;
      int id1 = dp[id][i - 1].first;
      if (id1 == -1) continue;
      dp[u][i] = {id1, dp[u][i - 1].second + dp[id][i - 1].second - sum[id][0] -
                           sum[id][1]};
      Next[u][i] = Next[id][i - 1];
    }
  }
  for (auto t : g[u]) {
    if (t.first == fa) continue;
    dfs2(t.first, u, deep + 1);
  }
}
long long fun(int x, int y) {
  if (x == y) return sum[x][0] + sum[x][1];
  long long ansx, ansy, ans = 0;
  ansx = sum[x][0] + sum[x][1];
  ansy = sum[y][0] + sum[y][1];
  int xx = 0, yy = 0;
  while (true) {
    if (h[x] > h[y]) {
      int i;
      for (i = 21; i >= 0; i--) {
        if (dp[x][i].first == -1) continue;
        int id = dp[x][i].first;
        if (h[y] <= h[id]) break;
      }
      ansx = ansx + dp[x][i].second - sum[x][1] - sum[x][0];
      xx = Next[x][i];
      x = dp[x][i].first;
    } else if (h[x] < h[y]) {
      int i;
      for (i = 21; i >= 0; i--) {
        if (dp[y][i].first == -1) continue;
        int id = dp[y][i].first;
        if (h[x] <= h[id]) break;
      }
      ansy = ansy + dp[y][i].second - sum[y][1] - sum[y][0];
      yy = Next[y][i];
      y = dp[y][i].first;
    } else {
      if (x == y) {
        ans = ansx + ansy;
        ans -= m[x][xx] + sum[x][1];
        ans -= m[y][yy] + sum[y][1];
        ans += sum[x][1];
        ans += w[x];
        for (auto t : g[x]) {
          if (t.first == Fa[x] || t.first == xx || t.first == yy) continue;
          if (sum[t.first][0] > 2 * t.second) {
            ans += sum[t.first][0] - 2 * t.second;
          }
        }
        break;
      } else {
        int i;
        for (i = 21; i >= 0; i--) {
          if (dp[x][i].first == -1) continue;
          if (Next[x][i] != Next[y][i]) break;
        }
        ansx = ansx + dp[x][i].second - sum[x][1] - sum[x][0];
        ansy = ansy + dp[y][i].second - sum[y][1] - sum[y][0];
        xx = Next[x][i];
        yy = Next[y][i];
        x = dp[x][i].first;
        y = dp[y][i].first;
      }
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  memset(sum, 0, sizeof(sum));
  memset(w, 0, sizeof(w));
  memset(h, 0, sizeof(h));
  memset(Next, -1, sizeof(Next));
  memset(Fa, -1, sizeof(Fa));
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 22; j++) dp[i][j] = {-1, -1};
  for (int i = 1; i <= n; i++) scanf("%lld", &w[i]);
  for (int i = 1; i < n; i++) {
    int u, v;
    long long cost;
    scanf("%d%d%lld", &u, &v, &cost);
    ask[u][v] = cost;
    ask[v][u] = cost;
    g[u].push_back({v, cost});
    g[v].push_back({u, cost});
  }
  dfs(1, -1);
  dfs1(1, -1, 0);
  dfs2(1, -1, 0);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%lld\n", fun(l, r));
  }
  return 0;
}
