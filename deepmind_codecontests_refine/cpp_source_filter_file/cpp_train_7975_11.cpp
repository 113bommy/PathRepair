#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, maxt = 2005;
int dp[maxn][maxt], pre[maxn][maxt];
class Node {
 public:
  int t, d, p, id;
} item[maxn];
bool comp(const Node& a, const Node& b) {
  if (a.d != b.d) return a.d < b.d;
  return a.p > b.p;
}
void print(int i, int t, int num) {
  if (i == 0) {
    printf("%d\n", num);
    return;
  }
  if (pre[i][t] == 0)
    print(i - 1, t, num);
  else {
    print(i - 1, t - item[i].t, num + 1);
    printf("%d ", item[i].id);
  }
}
int main() {
  int n;
  while (cin >> n) {
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++) {
      item[i].id = i;
      scanf("%d%d%d", &item[i].t, &item[i].d, &item[i].p);
    }
    sort(item, item + n, comp);
    for (int i = 1; i <= n; i++) {
      for (int t = 0; t <= maxt; t++) {
        dp[i][t] = dp[i - 1][t];
        if (t < item[i].t || t > item[i].d - 1) continue;
        if (dp[i][t] < dp[i - 1][t - item[i].t] + item[i].p) {
          dp[i][t] = dp[i - 1][t - item[i].t] + item[i].p;
          pre[i][t] = 1;
        }
      }
    }
    int ans = -1, c = 0;
    for (int i = 1; i <= maxt; i++) {
      if (dp[n][i] > ans) {
        ans = dp[n][i];
        c = i;
      }
    }
    cout << ans << endl;
    print(n, c, 0);
    cout << endl;
  }
}
