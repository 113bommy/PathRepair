#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n, m, _m, cnt, d[maxn], fa[maxn];
bool vis[maxn];
struct Edge {
  int x, y;
} Es[maxn];
long long ans;
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
void merge(int x, int y) {
  x = getfa(x);
  y = getfa(y);
  if (x != y) fa[x] = y;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x != y) {
      Es[++_m].x = x, Es[_m].y = y;
      d[x]++;
      d[y]++;
      vis[x] = vis[y] = true;
      merge(x, y);
    } else
      cnt++, vis[x] = true;
  }
  int rt = 0;
  for (int i = 1; i <= n; i++)
    if (vis) rt = i;
  if (!rt) return printf("0\n"), 0;
  for (int i = 1; i <= n; i++)
    if (vis[i] && getfa(rt) != getfa(i)) return printf("0\n"), 0;
  for (int i = 1; i <= _m; i++) ans += (d[Es[i].x] - 1) + (d[Es[i].y] - 1);
  ans = ans / 2 + (long long)_m * cnt + (long long)cnt * (cnt - 1) / 2;
  printf("%I64d\n", ans);
  return 0;
}
