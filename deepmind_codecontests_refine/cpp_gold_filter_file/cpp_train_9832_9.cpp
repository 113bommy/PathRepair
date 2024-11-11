#include <bits/stdc++.h>
using namespace std;
int cond = 1;
struct Edge {
  int a, b, cost;
};
bool operator<(Edge a, Edge b) { return a.cost < b.cost; }
const int N = 100005;
int pr[N][20];
int mx[N][20];
int n, m, q;
Edge ed[2 * N];
int p[N];
int gp(int x) {
  if (p[x] != x) p[x] = gp(p[x]);
  return p[x];
}
vector<pair<int, int> > e[N];
bool visited[N];
int in[N], out[N];
bool ancestor(int a, int b) { return in[a] <= in[b] && in[b] <= out[a]; }
int tim;
void dfs(int x) {
  in[x] = ++tim;
  visited[x] = true;
  for (int i = 1; i < 20; ++i) {
    pr[x][i] = pr[pr[x][i - 1]][i - 1];
    mx[x][i] = max(mx[x][i - 1], mx[pr[x][i - 1]][i - 1]);
  }
  for (__typeof((e[x]).begin()) it = ((e[x]).begin()); it != (e[x]).end();
       ++it) {
    if (!visited[it->first]) {
      pr[it->first][0] = x;
      mx[it->first][0] = it->second;
      dfs(it->first);
    }
  }
  out[x] = ++tim;
}
int firstAncestor(int a, int b) {
  int x = 0;
  while (!ancestor(a, b)) {
    int j = 0;
    while (pr[a][j] && !ancestor(pr[a][j], b)) ++j;
    if (j > 0) --j;
    x = max(x, mx[a][j]);
    a = pr[a][j];
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> ed[i].a >> ed[i].b >> ed[i].cost;
  sort(ed + 1, ed + m + 1);
  for (__typeof(1) i = (1); i <= (n); ++i) p[i] = i;
  long long res = 0;
  int cnt = n;
  for (int i = 1; i <= m; ++i) {
    if (gp(ed[i].a) != gp(ed[i].b)) {
      --cnt;
      res += ed[i].cost;
      e[ed[i].a].push_back(make_pair(ed[i].b, ed[i].cost));
      e[ed[i].b].push_back(make_pair(ed[i].a, ed[i].cost));
      p[gp(ed[i].a)] = gp(ed[i].b);
    }
  }
  dfs(1);
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int a, b;
    cin >> a >> b;
    if (cnt > 2) {
      printf("-1\n");
    } else if (cnt > 1) {
      if (gp(a) != gp(b))
        cout << res << "\n";
      else
        cout << "-1\n";
    } else {
      cout << res - max(firstAncestor(a, b), firstAncestor(b, a)) << "\n";
    }
  }
  return 0;
}
