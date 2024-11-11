#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int mod = 1000000007;
struct node {
  int x, y;
  node() {}
  node(int xx, int yy) : x(xx), y(yy) {}
  bool operator<(const node a) const {
    if (x == a.x) return y < a.y;
    return x < a.x;
  }
};
int a[100500];
int b[100500];
int c[100500];
int d[100500];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char s[100500];
int vis[100500];
int n, m;
int ans;
vector<int> g[100500];
vector<int> gg[100500];
int father[100500];
void init() {
  for (int i = 0; i < 100500; i++) father[i] = i;
}
int getfather(int x) {
  return father[x] == x ? x : father[x] = getfather(father[x]);
}
bool issame(int x, int y) { return getfather(x) == getfather(y); }
void unite(int x, int y) {
  x = getfather(x);
  y = getfather(y);
  if (x != y) father[x] = y;
}
int col[100500];
bool BFS(int st) {
  col[st] = 1;
  vis[st] = 1;
  queue<int> q;
  q.push(st);
  while (!q.empty()) {
    int k = q.front();
    q.pop();
    for (int i = 0; i < g[k].size(); i++) {
      int point = g[k][i];
      int cc = col[k] == 1 ? 2 : 1;
      if (col[point] == 0) {
        col[point] = cc;
        q.push(point);
        vis[point] = 1;
      } else if (col[point] != cc) {
        return false;
      }
    }
  }
  return true;
}
int main() {
  int tt, ca = 1;
  int p, q;
  scanf("%d %d", &n, &m);
  for (int i = (1); i < (n + 1); i++) scanf("%d", &a[i]);
  for (int i = (0); i < (m); i++) {
    scanf("%d", &p);
    for (int j = (0); j < (p); j++) {
      scanf("%d", &q);
      gg[q].push_back(i + 1);
    }
  }
  init();
  bool flag = true;
  vector<pair<int, int> > ve;
  for (int i = (1); i < (n + 1); i++) {
    if (a[i]) {
      unite(gg[i][0], gg[i][1]);
    }
  }
  bool f = 1;
  int st = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      int x = getfather(gg[i][0]);
      int y = getfather(gg[i][1]);
      if (x == y) {
        f = 0;
        break;
      }
      g[x].push_back(y);
      g[y].push_back(x);
      st = x;
    }
  }
  if (f == 1) {
    if (st != -1) {
      for (int i = 1; i <= n; i++)
        if (!vis[i] && !BFS(i)) {
          f = 0;
          break;
        }
    }
  }
  if (f)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
