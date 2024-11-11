#include <bits/stdc++.h>
using namespace std;
void reloc() {
  freopen("/Users/admin/Desktop/cards.in", "r", stdin);
  freopen("/Users/admin/Desktop/cards.out", "w", stdout);
  return;
}
const int maxn = 100000, maxm = 10, maxq = 400;
char a[maxn + 1][maxm + 1];
int n, m, qe, q;
int vis[maxq + 1][maxm + 1], lb, up;
pair<int, int> jp[maxn + 1][maxm + 1];
void read() {
  scanf("%d%d%d\n", &n, &m, &qe);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (j != m)
        scanf("%c", &a[i][j]);
      else
        scanf("%c\n", &a[i][j]);
    }
  }
  q = sqrt(n);
}
inline bool outofbound(int i, int j) {
  if (j == 0 || j == m + 1 || i < lb || i > up) return 1;
  return 0;
}
pair<int, int> dp(int i, int j) {
  if (outofbound(i, j)) return pair<int, int>(i, j);
  if (vis[i - lb + 1][j] == 1) return jp[i][j];
  if (vis[i - lb + 1][j] == -1) {
    vis[i - lb + 1][j] = 1;
    return jp[i][j] = pair<int, int>(-1, -1);
  }
  vis[i - lb + 1][j] = -1;
  if (a[i][j] == '^')
    jp[i][j] = dp(i - 1, j);
  else if (a[i][j] == '>')
    jp[i][j] = dp(i, j + 1);
  else
    jp[i][j] = dp(i, j - 1);
  vis[i - lb + 1][j] = 1;
  return jp[i][j];
}
void bf(int id) {
  lb = (id - 1) * q + 1, up = min(n, id * q);
  memset(vis, 0, sizeof(vis));
  for (int i = lb; i <= up; i++) {
    for (int j = 1; j <= m; j++) {
      if (vis[i - lb + 1][j] == 0) dp(i, j);
    }
  }
  return;
}
int tr(int id) { return ((id - 1) / q + 1); }
bool inb(int u, int v) {
  if (u < 1 || u > n || v < 1 || v > m) return 0;
  return 1;
}
pair<int, int> query(int u, int v) {
  pair<int, int> ans = pair<int, int>(u, v);
  for (; inb(ans.first, ans.second); ans = jp[ans.first][ans.second])
    ;
  return ans;
}
void work() {
  char c;
  int u, v;
  int k = int(double(n) / double(q) + 1);
  if (q * k - q == n) k--;
  for (int i = 1; i <= k; i++) bf(i);
  for (int i = 1; i <= qe; i++) {
    scanf("%c ", &c);
    if (c == 'A') {
      scanf("%d%d\n", &u, &v);
      pair<int, int> q = query(u, v);
      printf("%d %d\n", q.first, q.second);
    } else {
      scanf("%d %d %c\n", &u, &v, &c);
      a[u][v] = c;
      bf(tr(u));
    }
  }
  return;
}
int main() {
  read();
  work();
  return 0;
}
