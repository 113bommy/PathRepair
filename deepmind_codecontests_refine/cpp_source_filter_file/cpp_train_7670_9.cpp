#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf = 1000000007;
struct zero {
  int a, b;
} lib[55];
double dp[55][55][55];
bool vis[55][55][55];
int n;
long long ans;
double poi;
double judge;
bool cmp(zero a1, zero a2) { return (a1.a > a2.a); }
double dfs(int now, int fr, int aux) {
  if (now > n) return 0;
  if (vis[now][fr][aux]) return dp[now][fr][aux];
  double minn = inf;
  if (now < n && lib[now].a == lib[now + 1].a) {
    if (fr) minn = min(minn, dfs(now + 1, fr - 1, aux));
    minn =
        min(minn, dfs(now + 1, fr, aux + 1) + lib[now].a - judge * lib[now].b);
  } else if (now == n || lib[now].a != lib[now + 1].a) {
    if (fr) minn = min(minn, dfs(now + 1, fr + aux - 1, 0));
    minn = min(minn,
               dfs(now + 1, fr + aux + 1, 0) + lib[now].a - judge * lib[now].b);
  }
  dp[now][fr][aux] = minn, vis[now][fr][aux] = 1;
  return minn;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &lib[i].a);
  for (int r = 1; r <= n; r++) scanf("%d", &lib[r].b);
  sort(lib + 1, lib + n + 1, cmp);
  double l = 0, r = 1e8;
  while ((r - l) > eps) {
    judge = (l + r) / 2;
    memset(dp, 0, sizeof dp);
    memset(vis, 0, sizeof vis);
    if (dfs(1, 0, 0) <= 0)
      r = poi = judge;
    else
      l = judge;
  }
  ans = (ceil)((poi - eps) * 1000);
  cout << ans;
}
