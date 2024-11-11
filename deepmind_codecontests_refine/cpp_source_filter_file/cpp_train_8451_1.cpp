#include <bits/stdc++.h>
using namespace std;
const int maxn = 300050;
int T, n;
int cnt;
int num, ans;
int head[maxn], val[maxn];
struct edge {
  int to, next;
} e[maxn << 1];
void add(int u, int v) {
  e[++cnt].next = head[u];
  head[u] = cnt;
  e[cnt].to = v;
  val[u]++;
}
void dfs(int x, int fa, int dis) {
  if (dis > ans) {
    ans = dis, num = x;
  }
  for (int i = head[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) {
      continue;
    }
    dfs(y, x, dis + val[y]);
  }
}
int main() {
  int i, j, k;
  cin >> T;
  while (T--) {
    cin >> n;
    for (i = 1; i <= n; i++) {
      head[i] = 0;
      val[i] = -1;
    }
    cnt = 0;
    for (i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      add(u, v);
      add(v, u);
    }
    ans = -1;
    dfs(1, 0, val[1]);
    ans = -1;
    dfs(num, 0, val[num]);
    cout << ans + 2;
  }
  return 0;
}
