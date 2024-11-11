#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
const int maxn = 100005;
int a[maxn];
vector<int> b[maxn];
int dp[305];
bool cmp(int a, int b) { return a < b; }
void work() {
  int ans = 0;
  int len = s / e;
  for (int i = 1; i <= n; i++) {
    for (int j = min(len, i); j >= 1; j--) {
      vector<int>::iterator p =
          upper_bound(b[a[i]].begin(), b[a[i]].end(), dp[j - 1], cmp);
      if (p == b[a[i]].end()) continue;
      dp[j] = min(dp[j], *p);
      if (e * j + i + dp[j] <= s) ans = max(ans, j);
    }
  }
  printf("%d\n", ans);
}
int main() {
  while (scanf("%d%d%d%d", &n, &m, &s, &e) == 4) {
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i < maxn; i++) b[i].clear();
    for (int i = 1; i <= m; i++) {
      int x;
      scanf("%d", &x);
      b[x].push_back(i);
    }
    memset(dp, 0x33, sizeof dp);
    dp[0] = 0;
    work();
  }
  return 0;
}
