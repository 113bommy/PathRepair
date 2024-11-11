#include <bits/stdc++.h>
using namespace std;
struct node {
  int u, v, c;
  bool operator<(const node &t) const { return c < t.c; }
} a[300300];
int n, m;
int maxlen[300300];
int dp[300300];
int main() {
  while (cin >> n >> m) {
    memset(maxlen, 0, sizeof(maxlen));
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; ++i) scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].c);
    sort(a, a + m);
    int i = 0, j = 0;
    for (int i = 0; i < m; ++i) {
      while (a[j].c < a[i].c) maxlen[a[j].v] = max(maxlen[a[j].v], dp[j]), j++;
      dp[i] = maxlen[a[i].u] + 1;
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) ans = max(ans, dp[i]);
    cout << ans << endl;
  }
  return 0;
}
