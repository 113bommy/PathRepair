#include <bits/stdc++.h>
inline int getint() {
  int x = 0, p = 1;
  char c = getchar();
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
const int N = 10010;
int n, m, bad, cnt;
int vis[N], dep[N], f[N], g[N], hh[N];
vector<pair<int, int> > G[N];
vector<int> res;
void dfs(int x, int p, int d) {
  vis[x] = 1;
  dep[x] = d;
  for (int(i) = 0; (i) < (G[x].size()); (i)++) {
    int to = G[x][i].first, id = G[x][i].second;
    if (to == p) continue;
    if (!vis[to]) {
      hh[to] = id;
      dfs(to, x, d + 1);
      f[x] += f[to];
      g[x] += g[to];
    } else if (vis[to] == 1) {
      if (!((dep[x] - dep[to]) & 1)) {
        f[x]++;
        cnt++;
        bad = id;
      } else
        g[x]++;
    } else {
      if (!((dep[to] - dep[x]) & 1))
        f[x]--;
      else
        g[x]--;
    }
  }
  vis[x] = 2;
}
int main() {
  n = getint();
  m = getint();
  for (int(i) = 0; (i) < (m); (i)++) {
    int x = getint() - 1, y = getint() - 1;
    G[x].push_back(make_pair(y, i));
    G[y].push_back(make_pair(x, i));
  }
  memset(hh, -1, sizeof(hh));
  for (int(i) = 0; (i) < (n); (i)++)
    if (!vis[i]) dfs(i, -1, 0);
  if (!cnt) {
    printf("%d\n", m);
    for (int(i) = 0; (i) < (m); (i)++) printf("%d ", i + 1);
    return 0;
  }
  if (cnt == 1) res.push_back(bad);
  for (int(i) = 0; (i) < (n); (i)++)
    if (hh[i] != -1 && f[i] == cnt && !g[i]) res.push_back(hh[i]);
  sort(res.begin(), res.end());
  printf("%d\n", res.size());
  for (int(i) = 0; (i) < (res.size()); (i)++) printf("%d ", res[i] + 1);
  return 0;
}
