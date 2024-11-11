#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107;
const int MAXT = 2007;
const int MAXE = 207;
const int INF = 0x3f3f3f3f;
int n;
struct Item {
  int t, d, p, nu;
  Item() {}
  Item(int t, int d, int p) : t(t), d(d), p(p) {}
  bool operator<(Item i) const { return t < i.t; }
} item[MAXN];
struct Dp {
  vector<int> v;
  int val;
} dp[MAXT][MAXN];
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%d%d%d", &item[i].t, &item[i].d, &item[i].p);
      item[i].nu = i;
    }
    sort(item + 1, item + 1 + n);
    for (int i = 0; i < MAXT; i++)
      for (int j = 0; j <= n; j++) {
        dp[i][j].v.clear();
        dp[i][j].val = 0;
      }
    for (int i = 0; i < MAXT; i++) {
      for (int j = 1; j <= n; j++) {
        if (i - item[j].t >= 0 && i < item[j].d) {
          if (dp[i][j].val < dp[i - item[j].t][j - 1].val + item[j].p) {
            dp[i][j].val = dp[i - item[j].t][j - 1].val + item[j].p;
            dp[i][j].v = dp[i - item[j].t][j - 1].v;
            dp[i][j].v.push_back(item[j].nu);
          }
        }
        if (dp[i][j].val < dp[i][j - 1].val) {
          dp[i][j].val = dp[i][j - 1].val;
          dp[i][j].v = dp[i][j - 1].v;
        }
      }
    }
    int ans = 0;
    vector<int> v;
    for (int i = 0; i < MAXT; i++) {
      if (ans < dp[i][n].val) {
        ans = dp[i][n].val;
        v = dp[i][n].v;
      }
    }
    printf("%d\n%d\n", ans, (int)v.size());
    for (int i = 0; i < v.size(); i++)
      if (i == 0)
        printf("%d", v[i]);
      else
        printf(" %d", v[i]);
    putchar('\n');
  }
  return 0;
}
