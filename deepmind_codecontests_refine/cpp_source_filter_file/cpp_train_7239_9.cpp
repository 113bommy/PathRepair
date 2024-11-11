#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
const int hinf = 0x3f3f3f3f;
const long long mod = 1000000009;
struct edge {
  int l, h, w;
} Edge[50][50];
int n, ans;
int f[10];
void dfs(int u, int v, int flow, int cost) {
  if (u == n) {
    ans = max(ans, cost);
    return;
  }
  if (v > n) {
    if (!flow) {
      dfs(u + 1, u + 2, f[u + 1], cost);
    }
  } else {
    for (int i = Edge[u][v].l; i <= Edge[u][v].h && i <= flow; i++) {
      f[v] += i;
      dfs(u, v + 1, flow - i, cost + i * i + (!i ? 0 : Edge[u][v].w));
      f[v] -= i;
    }
  }
}
int main() {
  scanf("%d", &n);
  int s, ff, l, h, a;
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    scanf("%d%d%d%d%d", &s, &ff, &l, &h, &a);
    Edge[s][ff].l = l;
    Edge[s][ff].h = h;
    Edge[s][ff].w = a;
  }
  ans = -1;
  for (int i = 0; i < 5 * (n - 1); i++) {
    memset(f, 0, sizeof(f));
    dfs(1, 2, i, 0);
    if (ans >= 0) {
      printf("%d %d\n", i, ans);
      return 0;
    }
  }
  printf("-1 -1\n");
}
