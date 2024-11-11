#include <bits/stdc++.h>
using namespace std;
const int maxn = 222, maxm = maxn * maxn;
int he[maxm << 2 | 50], ne[maxm << 4], to[maxm << 4], w[maxm << 4], cnt = 1;
inline void addedge(int x, int y, int z) {
  ne[++cnt] = he[x], he[x] = cnt, to[cnt] = y, w[cnt] = z;
  ne[++cnt] = he[y], he[y] = cnt, to[cnt] = x, w[cnt] = 0;
}
int n, m, id[maxn][maxn][2], tot, S = 1, T = 2;
char a[maxn][maxn];
int dis[maxm << 2 | 50];
int bfs() {
  fill(dis + 1, dis + tot + 1, 0);
  dis[S] = 1;
  queue<int> q;
  q.push(S);
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int i = he[x]; i; i = ne[i]) {
      if (!dis[to[i]] && w[i]) {
        dis[to[i]] = dis[x] + 1;
        q.push(to[i]);
      }
    }
  }
  return dis[T];
}
int cur[maxm << 2 | 50];
int dfs(int x, int low) {
  if (x == T || low == 0) return low;
  int ans = 0;
  for (int i = cur[x]; i && ans != low; i = ne[i]) {
    cur[x] = i;
    if (dis[to[i]] == dis[x] + 1 && w[i]) {
      int qwq = dfs(to[i], min(low - ans, w[i]));
      ans += qwq;
      w[i] -= qwq;
      w[i ^ 1] += qwq;
    }
  }
  return ans;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    memcpy(cur, he, sizeof(int) * (1 + tot));
    ans += dfs(S, 1e9);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i] + 1;
  tot = 2;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '#') ans++;
      if (i != n && a[i][j] == '#' && a[i + 1][j] == '#')
        id[i][j][0] = ++tot, addedge(S, tot, 1);
      if (j != n && a[i][j] == '#' && a[i][j + 1] == '#')
        id[i][j][1] = ++tot, addedge(tot, T, 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int a = id[i - 1][j][0];
      int b = id[i][j][1];
      int c = id[i][j][0];
      int d = id[i][j - 1][1];
      if (a && b) addedge(a, b, 1);
      if (c && b) addedge(c, b, 1);
      if (a && d) addedge(a, d, 1);
      if (c && d) addedge(c, d, 1);
    }
  }
  cout << ans - ((tot - 2) - dinic());
}
