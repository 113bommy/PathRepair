#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, c = getchar(), f = 0;
  for (; c > '9' || c < '0'; f = c == '-', c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 1) + (x << 3) + c - '0', c = getchar())
    ;
  return f ? -x : x;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + 48);
}
const int mo = 1e9 + 7, N = 200000 + 10;
int n, ecnt, ans, root, head[N], p3[N], l3[N], ch[N][4], size[N], f[N], du[N];
bool vis[N], tag[N];
struct edge {
  int to, nxt;
} e[N * 2];
void renew(int &x, int y) {
  if ((x += y) >= mo) x -= mo;
}
int dp2(int x, int y);
int dp1(int x) {
  if (!x) return 1;
  if (vis[x]) return f[x];
  if (size[x] & 1) return 0;
  if (!tag[x]) return size[x] / 2;
  vis[x] = 1;
  if (*ch[x] == 1) {
    int y = p3[x];
    for (int i = (int)1, _y = 2; i <= _y; i++)
      if (!tag[ch[y][i]] && size[ch[y][i]] < l3[x] - 1)
        renew(f[x], dp1(ch[y][3 - i]));
    if (l3[x] & 1)
      for (int i = (int)1, _y = 2; i <= _y; i++) {
        int z = ch[y][i];
        if (*ch[z] == 0)
          renew(f[x], dp1(ch[y][3 - i]));
        else if (*ch[z] == 1)
          renew(f[x], dp2(ch[y][3 - i], ch[z][1]));
      }
    for (int i = (int)1, _y = 2; i <= _y; i++) {
      int z = ch[y][i];
      if (*ch[z] == 1 && size[ch[z][1]] < l3[x] && !tag[ch[z][1]])
        renew(f[x], dp1(ch[y][3 - i]));
      else if (*ch[z] == 2)
        for (int j = (int)1, _y = 2; j <= _y; j++)
          if (!tag[ch[z][j]] && size[ch[z][j]] < l3[x])
            renew(f[x], dp2(ch[y][3 - i], ch[z][3 - j]));
    }
  } else {
    for (int i = (int)1, _y = 2; i <= _y; i++)
      if (*ch[ch[x][i]] == 0)
        renew(f[x], dp1(ch[x][3 - i]));
      else if (*ch[ch[x][i]] == 1)
        renew(f[x], dp2(ch[x][3 - i], ch[ch[x][i]][1]));
  }
  return f[x];
}
int dp2(int x, int y) {
  if ((tag[x] && tag[y]) || (size[x] + size[y]) & 1) return 0;
  for (; x && y; x = ch[x][1], y = ch[y][1])
    if (*ch[x] == 2 || *ch[y] == 2) return 0;
  if (!x && !y) return 1;
  return *ch[x + y] ? dp1(x + y) : 0;
}
int calc(int x, int y, int z) {
  int res = 0;
  if (*ch[y] == 0)
    res = (long long)dp1(x) * dp1(z) % mo;
  else if (*ch[y] == 1)
    res = ((long long)dp1(x) * dp2(z, ch[y][1]) +
           (long long)dp1(z) * dp2(x, ch[y][1])) %
          mo;
  else if (*ch[y] == 2)
    res = ((long long)dp2(x, ch[y][1]) * dp2(z, ch[y][2]) +
           (long long)dp2(x, ch[y][2]) * dp2(z, ch[y][1])) %
          mo;
  return res;
}
void addedge(int u, int v) {
  e[++ecnt] = (edge){v, head[u]};
  head[u] = ecnt;
  e[++ecnt] = (edge){u, head[v]};
  head[v] = ecnt;
  du[u]++;
  du[v]++;
}
void dfs(int u, int fa) {
  if (du[u] == 3) tag[u] = 1;
  size[u] = 1;
  for (int i = head[u], v; i; i = e[i].nxt)
    if ((v = e[i].to) != fa) {
      ch[u][++*ch[u]] = v;
      dfs(v, u);
      tag[u] |= tag[v];
      size[u] += size[v];
    }
  if (*ch[u] == 0)
    l3[u] = 1;
  else if (*ch[u] == 1)
    l3[u] = l3[ch[u][1]] + 1, p3[u] = p3[ch[u][1]];
  else if (*ch[u] == 2)
    l3[u] = 1, p3[u] = u;
}
int main() {
  n = read();
  if (n == 1) return puts("2"), 0;
  for (int i = (int)1, _y = 2 * n - 1; i <= _y; i++) addedge(read(), read());
  for (int i = (int)1, _y = 2 * n; i <= _y; i++)
    if (du[i] > 3)
      return puts("0"), 0;
    else if (du[i] == 3)
      root = i;
  if (!root) return printf("%d\n", (int)((2ll * n * n - 2 * n + 4) % mo)), 0;
  dfs(root, 0);
  renew(ans, calc(ch[root][1], ch[root][2], ch[root][3]));
  renew(ans, calc(ch[root][1], ch[root][3], ch[root][2]));
  renew(ans, calc(ch[root][2], ch[root][1], ch[root][3]));
  renew(ans, calc(ch[root][2], ch[root][3], ch[root][1]));
  renew(ans, calc(ch[root][3], ch[root][1], ch[root][2]));
  renew(ans, calc(ch[root][3], ch[root][2], ch[root][1]));
  printf("%d\n", ans * 2 % mo);
}
