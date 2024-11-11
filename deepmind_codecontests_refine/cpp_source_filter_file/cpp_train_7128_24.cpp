#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[2020][2020];
vector<int> adj[4000400];
queue<int> q;
bool vis[4000400];
bool is(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.') return 1;
  return 0;
}
inline int pt(int i, int j) { return i * m + j; }
void act(int i, int j) {
  vis[pt(i, j)] = 1;
  if (is(i - 1, j))
    adj[pt(i, j)].push_back(pt(i - 1, j)),
        adj[pt(i - 1, j)].push_back(pt(i, j));
  if (is(i, j - 1))
    adj[pt(i, j)].push_back(pt(i, j - 1)),
        adj[pt(i, j - 1)].push_back(pt(i, j));
}
void doo(int u, int v) {
  int a = u / m, b = u % m, c = v / m, d = v % m;
  if (a == c) {
    if (d == b + 1)
      s[a][b] = '<', s[c][d] = '>';
    else
      s[a][b] = '>', s[c][d] = '<';
  } else {
    if (a == c + 1)
      s[a][b] = 'v', s[c][d] = '^';
    else
      s[a][b] = '^', s[c][d] = 'v';
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    getchar();
    for (int j = 0; j < m; j++) {
      s[i][j] = getchar();
      if (s[i][j] == '.') act(i, j);
    }
  }
  for (int i = 0; i < m * n; i++)
    if (adj[i].size() == 1) q.push(i);
  while (!q.empty()) {
    int i, u = q.front(), v = adj[u][0];
    q.pop();
    if (!vis[v]) break;
    vis[u] = vis[v] = 0;
    doo(u, v);
    for (i = 0; i < adj[v].size(); i++) {
      u = adj[v][i];
      for (int j = 0; j < adj[u].size(); j++) {
        if (adj[u][j] == v) {
          adj[u].erase(adj[u].begin() + j);
          break;
        }
      }
      if (adj[u].size() == 1 && vis[u]) q.push(u);
    }
  }
  bool fl = 1;
  for (int i = 0; i < m * n; i++)
    if (vis[i]) fl = 0;
  if (fl) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        putchar(s[i][j]);
      }
      puts("");
    }
  } else
    puts("Not unique");
  return 0;
}
