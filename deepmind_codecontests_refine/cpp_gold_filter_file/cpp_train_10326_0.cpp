#include <bits/stdc++.h>
using namespace std;
namespace zyt {
template <typename T>
inline bool read(T &x) {
  char c;
  bool f = false;
  x = 0;
  do c = getchar();
  while (c != EOF && c != '-' && !isdigit(c));
  if (c == EOF) return false;
  if (c == '-') f = true, c = getchar();
  do x = x * 10 + c - '0', c = getchar();
  while (isdigit(c));
  if (f) x = -x;
  return true;
}
template <typename T>
inline void write(T x) {
  static char buf[20];
  char *pos = buf;
  if (x < 0) putchar('-'), x = -x;
  do *pos++ = x % 10 + '0';
  while (x /= 10);
  while (pos > buf) putchar(*--pos);
}
const int N = 1.5e4 + 10;
int n, head[N], ecnt, cir[N << 1], dp[2][N << 1], sum[N << 1], size[N], tot[N],
    pcnt, now, ans;
bool vis[N], incir[N];
struct edge {
  int to, next;
} e[N << 1];
void add(const int a, const int b) {
  e[ecnt] = (edge){b, head[a]}, head[a] = ecnt++;
}
bool findrot(const int u, const int f) {
  if (vis[u]) {
    cir[pcnt++] = u, incir[u] = true;
    return true;
  }
  vis[u] = true;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (v == f) continue;
    if (findrot(v, u)) {
      if (u == cir[0])
        return false;
      else {
        cir[pcnt++] = u, incir[u] = true;
        return true;
      }
    }
  }
  return false;
}
void dfs(const int u, const int f) {
  size[u] = 1;
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (incir[v] || v == f) continue;
    dfs(v, u);
    size[u] += size[v];
    tot[u] += tot[v];
  }
  tot[u] += size[u];
}
void dfs2(const int u, const int fa) {
  ans = max(ans, now);
  for (int i = head[u]; ~i; i = e[i].next) {
    int v = e[i].to;
    if (incir[v] || v == fa) continue;
    size[u] -= size[v], now -= size[v];
    size[v] += size[u], now += size[u];
    dfs2(v, u);
    size[v] -= size[u], now -= size[u];
    size[u] += size[v], now += size[v];
    ;
  }
}
int work() {
  read(n);
  memset(head, -1, sizeof(int[n]));
  for (int i = 0; i < n; i++) {
    int a, b;
    read(a), read(b);
    add(a, b), add(b, a);
  }
  findrot(0, -1);
  memcpy(cir + pcnt, cir, sizeof(int[pcnt]));
  int s = 0;
  for (int i = 0; i < pcnt; i++)
    dfs(cir[i], -1), s += tot[cir[i]] - size[cir[i]];
  for (int i = 0; i < (pcnt << 1); i++)
    dp[1][i] = size[cir[i]], sum[i] = (i ? sum[i - 1] : 0) + size[cir[i]];
  for (int l = 2; l < pcnt; l++) {
    int now = l & 1;
    for (int i = 0, j = l - 1; j < (pcnt << 1); i++, j++)
      dp[now][i] = max(dp[now ^ 1][i], dp[now ^ 1][i + 1]) + sum[j] -
                   (i ? sum[i - 1] : 0);
  }
  for (int i = 0; i < pcnt; i++) {
    now = dp[(pcnt - 1) & 1][i + 1] + s + n;
    size[cir[i]] = n;
    dfs2(cir[i], -1);
  }
  write(ans);
  return 0;
}
}  // namespace zyt
int main() { return zyt::work(); }
