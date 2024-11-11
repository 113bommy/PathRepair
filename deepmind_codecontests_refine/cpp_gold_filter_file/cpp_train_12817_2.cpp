#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int head[N], to[N << 1], nxt[N << 1], len[N << 1], cnt;
inline void addedge(int x, int y, int z) {
  to[++cnt] = y, nxt[cnt] = head[x], head[x] = cnt, len[cnt] = z;
  to[++cnt] = x, nxt[cnt] = head[y], head[y] = cnt, len[cnt] = z;
}
int w[N];
long long ans = 0;
inline long long dfs(int x, int fa) {
  long long d1 = 0, d2 = 0;
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == fa) continue;
    long long t = dfs(to[i], x) - len[i];
    if (t > d1)
      d2 = d1, d1 = t;
    else if (t > d2)
      d2 = t;
  }
  ans = max(ans, w[x] + d1 + d2);
  return d1 + w[x];
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", w + i);
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    addedge(x, y, z);
  }
  dfs(1, 0);
  printf("%I64d\n", ans);
  return 0;
}
