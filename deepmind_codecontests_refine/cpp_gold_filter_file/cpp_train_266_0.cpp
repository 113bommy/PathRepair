#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T x = 0;
  char ch = getchar();
  bool fl = false;
  while (!isdigit(ch)) {
    if (ch == '-') fl = true;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return fl ? -x : x;
}
const int maxn = 2e4 + 10;
int stk[maxn << 1], top = 0, n, k, m;
int f[(1 << 21) + 5], len[maxn];
int dis[maxn], c[30][30];
bool vis[maxn];
void bfs(int s) {
  memset(dis, 0x3f, sizeof dis);
  queue<int> q;
  q.push(stk[s]);
  dis[stk[s]] = 0;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int i = 1; i <= m; i++) {
      if (u + len[i] <= n + 1 && dis[u + len[i]] > dis[u] + 1) {
        dis[u + len[i]] = dis[u] + 1;
        q.push(u + len[i]);
      }
      if (u - len[i] > 0 && dis[u - len[i]] > dis[u] + 1) {
        dis[u - len[i]] = dis[u] + 1;
        q.push(u - len[i]);
      }
    }
  }
  for (int i = 1; i <= top; i++) c[s][i] = dis[stk[i]];
}
int main() {
  memset(f, 0x3f, sizeof f);
  memset(c, 0x3f, sizeof c);
  n = read<int>();
  k = read<int>();
  m = read<int>();
  for (int i = 1; i <= k; i++) {
    int x = read<int>();
    vis[x] ^= 1;
    vis[x + 1] ^= 1;
  }
  for (int i = 1; i <= m; i++) len[i] = read<int>();
  for (int i = 1; i <= n + 1; i++)
    if (vis[i]) stk[++top] = i;
  for (int i = 1; i <= top; i++) bfs(i);
  f[0] = 0;
  for (int s = 0; s < (1 << top); s++) {
    for (int i = 1; i <= top; i++) {
      if ((s >> i - 1) & 1) continue;
      for (int j = i + 1; j <= top; j++) {
        if ((s >> j - 1) & 1) continue;
        f[s | (1 << i - 1) | (1 << j - 1)] =
            min(f[s | (1 << i - 1) | (1 << j - 1)], f[s] + c[i][j]);
      }
    }
  }
  if (f[(1 << top) - 1] > 1e9)
    puts("-1");
  else
    printf("%d\n", f[(1 << top) - 1]);
  return 0;
}
