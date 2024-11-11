#include <bits/stdc++.h>
using namespace std;
int n, m;
long long K;
struct node {
  int x, y;
  long long v;
  node(int x = 0, int y = 0, long long v = 0) : x(x), y(y), v(v) {}
} s[1000100];
long long a[1010][1010];
long long cnt = 0;
int fa[1000100], vis[1010][1010];
long long num[1000100];
bool cmp(node a, node b) { return a.v > b.v; }
int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, 1, 0, -1};
int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
void Union(int x, int y) {
  int X = find(x);
  int Y = find(y);
  if (X != Y) {
    fa[X] = Y;
    num[Y] += num[X];
    num[X] = 0;
  }
}
bool pd(node t) {
  if (t.x < 1 || t.x > n || t.y < 1 || t.y > m || vis[t.x][t.y]) return false;
  return true;
}
void solve(int X, int Y, long long t, long long V) {
  queue<node> qu;
  memset((vis), (0), sizeof(vis));
  qu.push(node(X, Y, V));
  vis[X][Y] = 1;
  t--;
  while (!qu.empty()) {
    node next, now = qu.front();
    qu.pop();
    for (int i = 0; i < 4; i++) {
      next.x = now.x + xx[i];
      next.y = now.y + yy[i];
      if (t == 0) continue;
      if (a[next.x][next.y] < V) continue;
      if (pd(next)) {
        vis[next.x][next.y] = 1;
        qu.push(next);
        t--;
      }
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i][j])
        cout << V << " ";
      else
        cout << 0 << " ";
    }
    cout << endl;
  }
}
int main() {
  cin >> n >> m >> K;
  for (int i = 0; i <= 1e6 + 10; i++) fa[i] = i, num[i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      s[++cnt] = node(i, j, a[i][j]);
    }
  }
  sort(s + 1, s + cnt + 1, cmp);
  for (int i = 1; i <= cnt; i++) {
    if (s[i].v == 0) break;
    int X = s[i].x, Y = s[i].y;
    node tmp;
    for (int j = 0; j < 4; j++) {
      tmp.x = X + xx[j];
      tmp.y = Y + yy[j];
      tmp.v = a[tmp.x][tmp.y];
      if (tmp.v >= s[i].v) {
        Union((X - 1) * m + Y, (tmp.x - 1) * m + tmp.y);
      }
    }
    long long Num = K / s[i].v;
    if (K % s[i].v) continue;
    int u = find((X - 1) * m + Y);
    if (Num <= num[u]) {
      solve(X, Y, Num, s[i].v);
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
