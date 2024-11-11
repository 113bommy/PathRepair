#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int pre[1005];
int fi(int x) {
  int i = x;
  while (x != pre[x]) x = pre[x];
  while (i != x) {
    int t = pre[i];
    pre[i] = x;
    i = t;
  }
  return x;
}
struct node {
  int w, b;
} ha[1005];
vector<int> ans[1005];
int dp[100005];
int main() {
  int n, m, w, x, y;
  scanf("%d%d%d", &n, &m, &w);
  for (int i = 1; i <= n; ++i) scanf("%d", &ha[i].w);
  for (int i = 1; i <= n; ++i) scanf("%d", &ha[i].b);
  for (int i = 1; i <= n; ++i) pre[i] = i;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y);
    x = fi(x), y = fi(y);
    pre[y] = x;
  }
  for (int i = 1; i <= n; ++i) ans[fi(i)].push_back(i);
  for (int i = 1; i <= n; ++i) {
    int su1 = 0, su2 = 0;
    if (ans[i].size() == 0) continue;
    for (int j = w; j > 0; --j) {
      if (su1 == 0 && su2 == 0) {
        if (ans[i].size() > 1)
          for (int f = 0; f < ans[i].size(); ++f)
            su1 += ha[ans[i][f]].w, su2 += ha[ans[i][f]].b;
      }
      if (j >= su1) dp[j] = max(dp[j - su1] + su2, dp[j]);
      for (int f = 0; f < ans[i].size(); ++f) {
        int w = ha[ans[i][f]].w, b = ha[ans[i][f]].b;
        if (j >= w) dp[j] = max(dp[j - w] + b, dp[j]);
      }
    }
  }
  int ma = dp[w];
  printf("%d", ma);
  return 0;
}
