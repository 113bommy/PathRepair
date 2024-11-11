#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
int n;
int a[N];
long long int d[N][2];
int vis[N][2];
int pre[N][2];
bool viss;
long long int dfs(int x, int ot) {
  if (x <= 0 || x > n) return 0;
  if (d[x][ot]) return d[x][ot];
  if (vis[x][ot]) return -1;
  if (pre[x][ot]) viss = true;
  vis[x][ot] = 1;
  if (!ot) {
    long long int tmp = dfs(x + a[x], 1);
    if (x + a[x] >= 1 && x + a[x] <= n) pre[x][ot] |= pre[x + a[x]][ot ^ 1];
    if (tmp >= 0)
      d[x][ot] = dfs(x + a[x], 1) + a[x];
    else
      d[x][ot] = -1;
  } else {
    long long int tmp = dfs(x - a[x], 0);
    if (x - a[x] >= 1 && x + a[x] <= n) pre[x][ot] |= pre[x - a[x]][ot ^ 1];
    if (tmp >= 0)
      d[x][ot] = dfs(x - a[x], 0) + a[x];
    else
      d[x][ot] = -1;
  }
  return d[x][ot];
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) scanf("%d", &a[i]);
  pre[1][1] = 1;
  for (int i = 1; i < n; ++i) {
    a[1] = i, viss = false;
    d[1][0] = d[1][1] = 0;
    vis[1][0] = vis[1][1] = 0;
    printf("%lld\n", dfs(1, 0) + (viss ? (i - 1) : 0));
  }
  return 0;
}
