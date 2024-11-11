#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, m;
int tot, bian[N], nxt[N], head[N], rd[N];
void add(int x, int y) {
  ++tot, bian[tot] = y, nxt[tot] = head[x], head[x] = tot, rd[y]++;
}
int ans = 1;
int c[N];
int v[N];
void dfs(int x) {
  v[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int y = bian[i];
    if (v[y]) {
      if (v[y] == 1) {
        c[i] = 2;
        ans = 2;
      } else {
        c[i] = 1;
      }
    } else {
      c[i] = 1;
      dfs(y);
    }
  }
  v[x] = 2;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
  }
  for (int i = 1; i <= n; ++i) {
    if (v[i]) continue;
    dfs(i);
  }
  cout << ans << endl;
  for (int i = 1; i <= m; ++i) {
    printf("%d ", c[i]);
  }
}
