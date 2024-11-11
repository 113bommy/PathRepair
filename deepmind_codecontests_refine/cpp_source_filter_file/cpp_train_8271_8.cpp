#include <bits/stdc++.h>
using std::max;
using std::min;
const int N = 8005, T = 10000;
int dp[N][4005], n, p, Q, mxt, v, w, t, L[T + 5], R[T + 5], cnt, r;
struct goods {
  int v, w;
};
std::vector<goods> e[10005];
void solve(int *dp, int t) {
  for (auto u : e[t]) {
    for (int i = 4000; i >= u.v; i--) dp[i] = max(dp[i], dp[i - u.v] + u.w);
  }
}
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &v, &w, &t);
    e[t].push_back({v, w});
    mxt = std::max(mxt, t);
  }
  scanf("%d", &Q);
  for (int i = 1; i <= T; i += p) {
    for (int j = i; j < i + p && j <= T; j++) {
      if (j > i) R[j] = R[j - 1];
      if (!e[j].empty()) {
        ++cnt;
        memcpy(dp[cnt], dp[R[j]], sizeof(dp[cnt]));
        solve(dp[cnt], j);
        R[j] = cnt;
      }
    }
    for (int j = i - 1; j > i - p && j; j--) {
      if (j < i - 1) L[j] = L[j + 1];
      if (!e[j].empty()) {
        ++cnt;
        memcpy(dp[cnt], dp[L[j]], sizeof(dp[cnt]));
        solve(dp[cnt], j);
        L[j] = cnt;
      }
    }
  }
  while (Q--) {
    scanf("%d%d", &r, &v);
    int l = r - p + 1;
    if (l < 0) l = 0;
    l = L[l], r = R[r];
    int ans = 0;
    for (int i = 0; i <= v; i++) ans = std::max(ans, dp[l][i] + dp[r][v - i]);
    printf("%d\n", ans);
  }
}
