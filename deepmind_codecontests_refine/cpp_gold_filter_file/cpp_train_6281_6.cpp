#include <bits/stdc++.h>
const int N = 100010, H = 20;
int tot = 0, max, s[H], first[N], deep[N], dfn[N], pos[N], c[N * 2], b[N], p[N],
    father[N][H];
long long dis[N];
struct data {
  int y, w, next;
} g[N * 2];
void add(int x, int y, int w) {
  g[++tot].y = y;
  g[tot].w = w;
  g[tot].next = first[x];
  first[x] = tot;
}
void dfs() {
  int top = 1, time = 1, i, u, v;
  b[1] = 1;
  dis[1] = 0;
  deep[1] = 0;
  dfn[1] = 1;
  pos[1] = 1;
  father[1][0] = 0;
  p[1] = first[1];
  while (top > 0) {
    if (p[top] == 0)
      top--;
    else if (g[p[top]].y == father[b[top]][0])
      p[top] = g[p[top]].next;
    else {
      u = b[top];
      v = g[p[top]].y;
      b[top + 1] = v;
      dis[v] = dis[u] + g[p[top]].w;
      deep[v] = deep[u] + 1;
      time++;
      dfn[v] = time;
      pos[time] = v;
      father[v][0] = u;
      i = 1;
      while (s[i] <= deep[v]) {
        father[v][i] = father[father[v][i - 1]][i - 1];
        i++;
      }
      p[top + 1] = first[v];
      p[top] = g[p[top]].next;
      top++;
    }
  }
}
void modify(int x, int w) {
  while (x <= s[max]) {
    c[x] += w;
    x += x & (-x);
  }
}
int query(int x) {
  int temp = 0;
  while (x > 0) {
    temp += c[x];
    x -= x & (-x);
  }
  return (temp);
}
int find(int w) {
  int l = 0, r = s[max], mid;
  while (l + 1 < r) {
    mid = (l + r) / 2;
    if (c[mid] < w) {
      w -= c[mid];
      l = mid;
    } else
      r = mid;
  }
  return (pos[r]);
}
void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}
int lca(int x, int y) {
  int i;
  if (deep[x] < deep[y]) swap(x, y);
  for (i = max; i >= 0; i--)
    if (deep[x] - s[i] >= deep[y]) x = father[x][i];
  if (x == y) return (x);
  for (i = max; i >= 0; i--)
    if (deep[x] >= s[i])
      if (father[x][i] != father[y][i]) {
        x = father[x][i];
        y = father[y][i];
      }
  return (father[x][0]);
}
int main() {
  int n, m, i, j, x, y, w, t, sum = 0;
  long long ans = 0;
  char q[3];
  scanf("%d", &n);
  memset(first, 0, sizeof(first));
  for (i = 1; i < n; i++) {
    scanf("%d %d %d", &x, &y, &w);
    add(x, y, w);
    add(y, x, w);
  }
  i = 0;
  s[0] = 1;
  while (s[i] < n) {
    s[i + 1] = s[i] * 2;
    i++;
  }
  max = i;
  dfs();
  memset(c, 0, sizeof(c));
  scanf("%d", &m);
  while (m--) {
    scanf("%s", q);
    if (q[0] == '?')
      printf("%I64d\n", ans);
    else {
      scanf("%d", &t);
      if (q[0] == '+') {
        if (sum > 0) {
          w = query(dfn[t]);
          if (w == 0 || w == sum) {
            x = find(1);
            y = find(sum);
          } else {
            x = find(w);
            y = find(w + 1);
          }
          ans += dis[t] - dis[lca(x, t)] - dis[lca(y, t)] + dis[lca(x, y)];
        }
        modify(dfn[t], 1);
        sum++;
      } else {
        if (sum > 1) {
          w = query(dfn[t]);
          if (w == 1) {
            x = find(2);
            y = find(sum);
          } else if (w == sum) {
            x = find(1);
            y = find(sum - 1);
          } else {
            x = find(w - 1);
            y = find(w + 1);
          }
          ans -= dis[t] - dis[lca(x, t)] - dis[lca(y, t)] + dis[lca(x, y)];
        }
        modify(dfn[t], -1);
        sum--;
      }
    }
  }
  return (0);
}
