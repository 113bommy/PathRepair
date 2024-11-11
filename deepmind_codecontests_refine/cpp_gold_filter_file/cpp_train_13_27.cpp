#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, nxxt;
} e[200005 << 1];
queue<int> q;
vector<int> v[200005];
bool vis[200005];
int head[200005], cnt = 1, n, m, a[200005], id[200005], b[200005], tot,
                  rd[200005], tb[200005], xr[200005], mx;
inline void ins(int u, int v) {
  e[cnt] = (edge){v, head[u]};
  head[u] = cnt++;
}
int main() {
  memset(id, -1, sizeof(id));
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    ins(x, y);
    rd[y]++;
  }
  for (int i = 1; i <= n; i++)
    if (!rd[i]) q.push(i);
  while (!q.empty()) {
    int a1 = q.front();
    q.pop();
    b[++tot] = a1;
    for (int i = head[a1]; i; i = e[i].nxxt) {
      int j = e[i].to;
      rd[j]--;
      if (!rd[j]) q.push(j);
    }
  }
  for (int i = n; i; i--) {
    int x = b[i];
    tot = 0;
    for (int j = head[x]; j; j = e[j].nxxt) {
      tb[++tot] = id[e[j].to];
    }
    sort(tb + 1, tb + 1 + tot);
    if (tb[1] > 0 || !tot)
      id[x] = 0;
    else {
      for (int j = 1; j < tot; j++)
        if (tb[j] + 1 < tb[j + 1]) {
          id[x] = tb[j] + 1;
          break;
        }
      if (id[x] < 0) id[x] = tb[tot] + 1;
    }
  }
  for (int i = 1; i <= n; i++) xr[id[i]] ^= a[i];
  bool flag = false;
  for (int i = 0; i <= n; i++)
    if (xr[i]) {
      flag = true;
      break;
    }
  if (!flag) {
    puts("LOSE");
    return 0;
  }
  puts("WIN");
  for (int i = 1; i <= n; i++) mx = max(mx, id[i]);
  for (int i = 1; i <= n; i++) v[id[i]].push_back(i);
  for (int i = mx; ~i; i--)
    if (xr[i]) {
      int te;
      for (int j = 0; j < v[i].size(); j++) {
        int to = v[i][j];
        if ((xr[i] ^ a[to]) < a[to]) {
          te = v[i][j];
          break;
        }
      }
      a[te] ^= xr[i];
      for (int j = head[te]; j; j = e[j].nxxt) {
        int to = e[j].to;
        if (!vis[id[to]]) {
          a[to] ^= xr[id[to]];
          vis[id[to]] = 1;
        }
      }
      break;
    }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  puts("");
}
