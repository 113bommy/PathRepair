#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int maxn = 400000 + 5;
int head[maxn], ver[maxn], edge[maxn], nex[maxn];
int pn;
int n;
long long cnt[maxn][3][3];
long long ans = 0;
void addedge(int a, int b, int w);
void dfs(int a, int fa);
int main() {
  scanf("%d", &n);
  pn = 1;
  memset(head, 0, sizeof(head));
  for (int i = 1; i <= n - 1; i++) {
    int a, b, w;
    scanf("%d%d%d", &a, &b, &w);
    addedge(a, b, w);
    addedge(b, a, w);
  }
  memset(cnt, 0, sizeof(cnt));
  dfs(1, -1);
  printf("%lld\n", ans);
  return 0;
}
void addedge(int a, int b, int w) {
  ver[++pn] = b;
  edge[pn] = w;
  nex[pn] = head[a];
  head[a] = pn;
}
void dfs(int a, int fa) {
  for (int p = head[a]; p; p = nex[p])
    if (ver[p] != fa) {
      const int &b = ver[p];
      dfs(b, a);
      if (edge[p]) {
        cnt[a][1][1] += cnt[b][1][1] + 1;
        cnt[a][0][1] += cnt[b][0][1] + cnt[b][0][0];
      } else {
        cnt[a][1][0] += cnt[b][1][0] + cnt[b][1][1];
        cnt[a][0][0] += cnt[b][0][0] + 1;
      }
    }
  ans += cnt[a][1][0];
  ans += (cnt[a][1][1] + cnt[a][0][0]) * 2;
  ans += cnt[a][0][1];
  for (int p = head[a]; p; p = nex[p])
    if (ver[p] != fa) {
      const int &b = ver[p];
      if (edge[p]) {
        cnt[a][1][1] -= cnt[b][1][1] + 1;
        cnt[a][0][1] -= cnt[b][0][1] + cnt[b][0][0];
        ans +=
            (cnt[b][1][1] + 1) * (cnt[a][0][1] + cnt[a][0][0] + cnt[a][1][1]);
      } else {
        cnt[a][1][0] -= cnt[b][1][0] + cnt[b][1][1];
        cnt[a][0][0] -= cnt[b][0][0] + 1;
        ans += (cnt[b][0][0] + cnt[b][1][1] + cnt[b][1][0] + 1) * cnt[a][0][0];
      }
      if (edge[p]) {
        cnt[a][1][1] += cnt[b][1][1] + 1;
        cnt[a][0][1] += cnt[b][0][1] + cnt[b][0][0];
      } else {
        cnt[a][1][0] += cnt[b][1][0] + cnt[b][1][1];
        cnt[a][0][0] += cnt[b][0][0] + 1;
      }
    }
}
