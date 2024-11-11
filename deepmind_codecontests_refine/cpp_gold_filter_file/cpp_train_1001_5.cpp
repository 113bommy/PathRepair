#include <bits/stdc++.h>
using namespace std;
int n, m;
const int Maxn = 100005;
struct Edge {
  int x, y;
  long long val;
  int wh(int p) { return (x == p) ? y : x; }
} Link[Maxn];
vector<int> E[Maxn];
int fa[Maxn];
int Findfa(int x) {
  if (fa[x] == x) return x;
  return fa[x] = Findfa(fa[x]);
}
int f[Maxn][20];
int deep[Maxn];
long long v[Maxn];
void Dfs(int x, int depth) {
  deep[x] = depth;
  for (int i = 0, s = E[x].size(); i < s; ++i) {
    int y = Link[E[x][i]].wh(x);
    if (y == f[x][0]) continue;
    f[y][0] = x;
    Dfs(y, depth + 1);
    Link[E[x][i]].val = v[y];
    v[x] -= v[y];
  }
}
int root;
int LCA(int x, int y) {
  if (deep[x] < deep[y]) swap(x, y);
  for (int i = 18; ~i; --i)
    if (deep[x] - (1 << i) >= deep[y]) x = f[x][i];
  if (x == y) return x;
  for (int i = 18; ~i; --i) {
    if (f[x][i] ^ f[y][i]) x = f[x][i], y = f[y][i];
  }
  return f[x][0];
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) fa[i] = i, scanf("%lld", &v[i]);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    Link[i] = (Edge){x, y, 0};
    int f1 = Findfa(x), f2 = Findfa(y);
    if (f1 == f2) continue;
    fa[f1] = f2;
    E[x].push_back(i);
    E[y].push_back(i);
  }
  srand(time(0));
  root = rand() % n + 1;
  Dfs(root, 1);
  for (int i = 1; i <= 18; ++i)
    for (int x = 1; x <= n; ++x) f[x][i] = f[f[x][i - 1]][i - 1];
  if (abs(v[root]) & 1)
    puts("NO");
  else {
    bool flag = false;
    for (int i = 1; i <= m; ++i) {
      int x = Link[i].x, y = Link[i].y;
      if (f[x][0] == y || f[y][0] == x) continue;
      int lca = LCA(x, y);
      int size = deep[x] + deep[y] - 2 * deep[lca] + 1;
      if (size & 1) {
        int dlt = (deep[x] & 1) ? -1 : 1;
        dlt *= v[root] / 2;
        Link[i].val += dlt * -1;
        while (x != lca) {
          int p = f[x][0];
          for (int j = 0, s = E[p].size(); j < s; ++j) {
            if (Link[E[p][j]].wh(p) == x) {
              Link[E[p][j]].val += dlt;
              break;
            }
          }
          dlt *= -1;
          x = p;
        }
        dlt = (deep[y] & 1) ? -1 : 1;
        dlt *= v[root] / 2;
        while (y != lca) {
          int p = f[y][0];
          for (int j = 0, s = E[p].size(); j < s; ++j) {
            if (Link[E[p][j]].wh(p) == y) {
              Link[E[p][j]].val += dlt;
              break;
            }
          }
          dlt *= -1;
          y = p;
        }
        dlt *= 2;
        while (lca != root) {
          int p = f[lca][0];
          for (int j = 0, s = E[p].size(); j < s; ++j) {
            if (Link[E[p][j]].wh((p)) == lca) {
              Link[E[p][j]].val += dlt;
              break;
            }
          }
          dlt *= -1;
          lca = p;
        }
        flag = true;
        break;
      }
    }
    if (flag || v[root] == 0) {
      puts("YES");
      for (int i = 1; i <= m; ++i) printf("%lld\n", Link[i].val);
    } else
      puts("NO");
  }
  return 0;
}
