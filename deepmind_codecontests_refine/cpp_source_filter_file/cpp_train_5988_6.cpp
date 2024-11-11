#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n;
int a[N];
int f[N][N];
int vis[N][N];
int dfs(int l, int r) {
  if (vis[l][r]) return f[l][r];
  vis[l][r] = 1;
  f[l][r] = 1e9;
  if (l > r) return f[l][r] = 0;
  if (l == r) return f[l][r] = 1;
  if (l == r - 1) {
    if (a[l] == a[r])
      return f[l][r] = 1;
    else
      return f[l][r] = 2;
  }
  if (a[l] == a[r]) f[l][r] = dfs(l + 1, r - 1);
  for (int i = 1; i <= r; i++) {
    f[l][r] = min(dfs(l, i) + dfs(i + 1, r), f[l][r]);
  }
  return f[l][r];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  printf("%d\n", dfs(1, n));
  return 0;
}
