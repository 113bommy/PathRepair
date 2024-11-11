#include <bits/stdc++.h>
using namespace std;
namespace Dinic {
const int maxn = 2010, maxm = 50000;
const int inf = 1e9;
int n, m, S, T;
int cur[maxn], level[maxn];
struct edge {
  int to, flow, rev;
} e[maxm];
vector<int> g[maxn];
inline void addedge(int x, int y, int fl) {
  ++m;
  e[m] = (edge){y, fl, m + 1};
  g[x].push_back(m);
  ++m;
  e[m] = (edge){x, 0, m - 1};
  g[y].push_back(m);
}
void Init(int nn, int s, int t) {
  n = nn;
  S = s, T = t;
  for (int i = 0; i < nn; ++i) g[i].clear();
  m = 0;
}
bool Bfs(void) {
  fill(level, level + n, -1);
  queue<int> q;
  while (!q.empty()) q.pop();
  level[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x == T) return 1;
    for (int i = 0; i < (int)g[x].size(); ++i) {
      int num = g[x][i];
      int y = e[num].to;
      if (level[y] == -1 && e[num].flow) level[y] = level[x] + 1, q.push(y);
    }
  }
  return 0;
}
int Dfs(int x, int fl) {
  if (x == T || fl == 0) return fl;
  int tmp, cnt = 0;
  for (int &i = cur[x]; i < (int)g[x].size(); ++i) {
    int num = g[x][i];
    int y = e[num].to;
    if (e[num].flow && level[y] == level[x] + 1) {
      tmp = Dfs(y, min(fl - cnt, e[num].flow));
      e[num].flow -= tmp;
      e[e[num].rev].flow += tmp;
      cnt += tmp;
      if (cnt == fl) return cnt;
    }
  }
  if (!cnt) level[x] = -1;
  return cnt;
}
int Solve(void) {
  int ans = 0;
  while (Bfs()) {
    fill(cur, cur + n, 0);
    ans += Dfs(S, inf);
  }
  return ans;
}
}  // namespace Dinic
const int maxn = 1000, maxm = 1000;
int n, m, k, d[maxn], ans[maxm];
pair<int, int> e[maxm], pos[maxm];
vector<int> col[maxn];
int cas;
int main(void) {
  scanf("%d", &cas);
  while (cas--) {
    scanf("%d%d%d", &n, &m, &k);
    int s = 0, t = n + m + 1;
    Dinic::Init(n + m + 2, s, t);
    fill(d + 1, d + 1 + n, 0);
    for (int i = 1, x, y; i <= m; ++i) {
      scanf("%d%d", &x, &y);
      e[i] = make_pair(x, y);
      Dinic::addedge(s, i, 1);
      Dinic::addedge(i, m + x, 1);
      pos[i].first = Dinic::m;
      Dinic::addedge(i, m + y, 1);
      pos[i].second = Dinic::m;
      ++d[x], ++d[y];
    }
    int F = 0;
    for (int i = 1; i <= n; ++i) {
      F += max(0, (d[i] - k) * 2);
      Dinic::addedge(m + i, t, max(0, (d[i] - k) * 2));
    }
    int result = Dinic::Solve();
    if (result != F) {
      for (int i = 1; i <= m; ++i) printf("0 ");
      printf("\n");
    } else {
      for (int i = 1; i <= n; ++i) col[i].clear();
      for (int i = 1; i <= m; ++i) {
        int x = pos[i].first, y = pos[i].second;
        if (Dinic::e[x].flow)
          col[e[i].first].push_back(i);
        else if (Dinic::e[y].flow)
          col[e[i].second].push_back(i);
      }
      fill(ans + 1, ans + 1 + n, 0);
      int num = 0;
      for (int i = 1; i <= n; ++i)
        for (int j = 0; j < (int)col[i].size(); j += 2) {
          ans[col[i][j]] = ans[col[i][j + 1]] = ++num;
        }
      for (int i = 1; i <= m; ++i)
        if (ans[i] == 0)
          printf("%d ", ++num);
        else
          printf("%d ", ans[i]);
      printf("\n");
    }
  }
  return 0;
}
