#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
int n, Min, d1[N], d2[N];
int cnt = 1, head[N << 1], to[N << 1], nxt[N << 1], dir[N << 1];
void add_edge(int x, int y, int z) {
  nxt[++cnt] = head[x];
  to[cnt] = y;
  dir[cnt] = z;
  head[x] = cnt;
}
int dfs1(int x, int fa) {
  d1[x] = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    d1[x] += dir[i] + dfs1(y, x);
  }
  return d1[x];
}
void dfs2(int x, int fa) {
  for (int i = head[x]; i; i = nxt[i]) {
    int y = to[i];
    if (y == fa) continue;
    if (dir[i] == 0) d2[y] = d2[x] + 1;
    if (dir[i] == 1) d2[y] = d2[x] - 1;
    Min = min(Min, d2[y]);
    dfs2(y, x);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add_edge(x, y, 0);
    add_edge(y, x, 1);
  }
  dfs1(1, 0);
  d2[1] = d1[1];
  Min = INF;
  dfs2(1, 0);
  cout << Min << endl;
  for (int i = 1; i <= n; i++)
    if (d2[i] == Min) printf("%d ", i);
  return 0;
}
