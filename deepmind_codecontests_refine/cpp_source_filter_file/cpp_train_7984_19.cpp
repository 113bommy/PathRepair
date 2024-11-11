#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX / 1000;
const int maxn = 2005;
int dp[maxn], umb[maxn];
int a, n, m, x, w;
bool book[maxn];
int main() {
  cin >> a >> n >> m;
  while (n--) {
    scanf("%d%d", &x, &w);
    for (int i = x + 1; i <= w; i++) book[i] = true;
  }
  fill(umb, umb + maxn, inf);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &w);
    umb[x] = min(umb[x], w);
  }
  fill(dp + 1, dp + maxn, inf);
  for (int i = 1; i <= a; i++) {
    if (book[i]) {
      for (int j = 0; j < i; j++) {
        if (dp[j] != inf) dp[i] = min(dp[i], dp[j] + umb[j] * (i - j));
      }
    } else
      dp[i] = dp[i - 1];
  }
  cout << (dp[a] == inf ? -1 : dp[a]) << endl;
  return 0;
}
