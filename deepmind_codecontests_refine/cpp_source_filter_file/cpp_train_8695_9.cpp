#include <bits/stdc++.h>
using namespace std;
int a[1010][1010], id[1010][1010], f[1000100], ans[1010][1010], fa[1000100];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, m, CNT;
bool vis[1010][1010];
bool vst[1000100];
bool vs[1010][1010];
int Find(int x) { return ~fa[x] ? fa[x] = Find(fa[x]) : x; }
void uni(int a, int b) {
  int fx = Find(a), fb = Find(b);
  if (fx != fb) fa[fb] = fx;
}
inline bool out(int x, int y) { return x < 1 || x > n || y < 1 || y > m; }
int dfs(int x, int y, int c, int v) {
  if (~id[x][y]) {
    int t = id[x][y];
    int ans = f[Find(t)];
    if (Find(t) == Find(c)) return 0;
    uni(t, c);
    return ans;
  }
  id[x][y] = c;
  vis[x][y] = 1;
  int ans = 1;
  for (int i = 0; i < 4; i++) {
    int X = x + dx[i], Y = y + dy[i];
    if (out(X, Y)) continue;
    if (a[X][Y] < v) continue;
    if (vis[X][Y]) continue;
    ans += dfs(X, Y, c, v);
  }
  vis[x][y] = 0;
  return f[Find(c)] = ans;
}
struct node {
  int x, y, v;
  bool operator<(const node& a) const { return v < a.v; }
};
void gene(int x, int y, int v) {
  if (vs[x][y]) return;
  if (CNT < 0) return;
  CNT--;
  vs[x][y] = 1;
  ans[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int X = x + dx[i], Y = y + dy[i];
    if (out(X, Y)) continue;
    if (v > a[X][Y]) continue;
    gene(X, Y, v);
  }
}
int main() {
  memset(fa, 0xff, sizeof fa);
  memset(id, 0xff, sizeof id);
  long long k;
  priority_queue<node> q;
  scanf("%d %d %lld", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      q.push((node){i, j, a[i][j]});
    }
  }
  int num = 0;
  while (q.size()) {
    node a = q.top();
    q.pop();
    if (~id[a.x][a.y]) continue;
    int cnt = dfs(a.x, a.y, ++num, a.v);
    if (k % a.v) continue;
    if (1ll * cnt * a.v >= k) {
      puts("YES");
      CNT = k / a.v;
      gene(a.x, a.y, a.v);
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          printf("%d%c", ans[i][j] * a.v, " \n"[j == m]);
        }
      }
      return 0;
    }
  }
  puts("NO");
  return 0;
}
