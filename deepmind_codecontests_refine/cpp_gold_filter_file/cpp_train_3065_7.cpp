#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 350000;
vector<long long> vc[N];
long long dp[N];
long long a[N], b[N];
long long n, m, k, s, e;
void run() {
  int ans = 0;
  memset(dp, INF, sizeof(dp));
  dp[0] = -1;
  vector<long long>::iterator it;
  scanf("%lld%lld%lld%lld", &n, &m, &s, &e);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < m; ++i) scanf("%lld", &b[i]);
  for (int i = 0; i < m; ++i) vc[b[i]].push_back(i);
  for (int i = 0; i < n; ++i)
    for (int j = s / e; j >= 1; --j) {
      it = upper_bound(vc[a[i]].begin(), vc[a[i]].end(), dp[j - 1]);
      if (it == vc[a[i]].end()) continue;
      dp[j] = min(*it, dp[j]);
      if (i + 1 + dp[j] + 1 + j * e <= s) ans = max(ans, j);
    }
  printf("%d\n", ans);
}
int main() {
  run();
  return 0;
}
