#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")
int n;
bool vis[2003][2003];
pair<double, int> dp[2003][2003];
double pa[2003], pb[2003], pab[2003], cost;
pair<double, int> solve2(int pos, int a) {
  if (pos >= n) return make_pair(0.0, 0);
  if (vis[pos][a]) return dp[pos][a];
  double ans = solve2(pos + 1, a).first;
  int qtdB = solve2(pos + 1, a).second;
  if ((solve2(pos + 1, a).first + pb[pos] - cost) > ans) {
    ans = solve2(pos + 1, a).first + pb[pos] - cost;
    qtdB = solve2(pos + 1, a).second + 1;
  }
  if (a > 0) {
    if ((solve2(pos + 1, a - 1).first + pa[pos]) > ans) {
      ans = solve2(pos + 1, a - 1).first + pa[pos];
      qtdB = solve2(pos + 1, a - 1).second;
    }
    if ((solve2(pos + 1, a - 1).first + pab[pos] - cost) > ans) {
      ans = solve2(pos + 1, a - 1).first + pab[pos] - cost;
      qtdB = solve2(pos + 1, a - 1).second + 1;
    }
  }
  vis[pos][a] = true;
  return dp[pos][a] = make_pair(ans, qtdB);
}
double solve(int a, int b) {
  register int i, j;
  int limit = 30, qtdB;
  double left = 0.0, mid, right = 1.0, ans;
  while (limit--) {
    mid = (left + right) / 2.0;
    for (i = 0; i <= n; i++) {
      for (j = 0; j <= a; j++) vis[i][j] = false;
    }
    cost = mid;
    qtdB = solve2(0, a).second;
    if (qtdB <= b)
      right = mid;
    else
      left = mid;
  }
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= a; j++) vis[i][j] = false;
  }
  cost = right;
  ans = solve2(0, a).first + ((double)solve2(0, a).second) * cost;
  return ans;
}
int main() {
  int a, b;
  scanf("%d %d %d", &n, &a, &b);
  for (int i = 0; i < n; i++) scanf("%lf", &pa[i]);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &pb[i]);
    pb[i] -= 1e-12 * ((double)i);
  }
  for (int i = 0; i < n; i++) pab[i] = pa[i] + (1.0 - pa[i]) * pb[i];
  printf("%.17f\n", solve(a, b));
  return 0;
}
