#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = 40005;
int n, m, Q, nd, co, dx[15], dy[15];
int id[N][N], a[M], to[M], vis[M];
vector<int> e[M], vec[M];
char s[N][N], ss[1000005];
int q[M], bel[M], ava[M][15];
void solve() {
  scanf("%s", ss + 1);
  int len = strlen(ss + 1), h = 0, t = 0;
  for (int i = (int)(1); i <= (int)(nd); i++) bel[i] = -1;
  for (int i = (int)(1); i <= (int)(co); i++) {
    int pos = len;
    for (; pos && ava[i][ss[pos] - '0']; --pos)
      ;
    if (!pos) return puts("YES"), void(0);
    for (auto j : vec[i]) bel[j] = pos, q[++t] = j;
  }
  while (h != t) {
    int x = q[++h];
    for (auto i : e[x])
      if (bel[i] == -1) {
        int nv = bel[x] - ((ss[bel[x]] - '0') == a[i]);
        if (!nv) return puts("YES"), void(0);
        bel[i] = nv;
        q[++t] = i;
      }
  }
  puts("NO");
}
int main() {
  scanf("%d%d%d", &n, &m, &Q);
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%s", s[i] + 1);
  for (int i = (int)(0); i <= (int)(9); i++) scanf("%d%d", &dx[i], &dy[i]);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++)
      id[i][j] = ++nd, a[nd] = s[i][j] - '0';
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(m); j++) {
      int c = s[i][j] - '0';
      int nx = i + dx[c], ny = j + dy[c];
      if (nx < 1 || ny < 1 || nx > n || ny > m) nx = i, ny = j;
      to[id[i][j]] = id[nx][ny];
    }
  for (int i = (int)(1); i <= (int)(nd); i++) e[to[i]].push_back(i);
  for (int i = (int)(1); i <= (int)(nd); i++)
    if (!vis[i]) {
      int x = i;
      ++*vis;
      for (; !vis[x]; x = to[x]) vis[x] = *vis;
      if (vis[x] != *vis) continue;
      ++co;
      for (int y = x;;) {
        ava[co][a[y]] = 1;
        vec[co].push_back(y);
        if (to[y] == x) break;
        y = to[y];
      }
    }
  while (Q--) solve();
}
