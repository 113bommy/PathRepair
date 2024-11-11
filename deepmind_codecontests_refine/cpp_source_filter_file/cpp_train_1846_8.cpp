#include <bits/stdc++.h>
using namespace std;
int sum[200010];
vector<int> seq[200010];
map<int, int> vis;
int n, k, val;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k);
    for (int j = 1; j <= k; ++j) {
      scanf("%d", &val);
      seq[i].push_back(val);
      sum[i] += val;
    }
  }
  bool ok = 0;
  int l, r, tar;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < seq[i].size(); ++j) {
      int nval = seq[i][j];
      if (!vis[sum[i] - nval] || vis[sum[i] - nval] == i)
        vis[sum[i] - nval] = i;
      else
        l = i, r = vis[sum[i] - nval], ok = 1, tar = sum[i] - nval;
    }
    if (ok) break;
  }
  if (!ok)
    printf("NO");
  else {
    int lval = 0, rval = 0;
    for (int i = 0; i < seq[l].size(); ++i)
      if (seq[l][i] == sum[l] - tar) lval = i + 1;
    for (int i = 0; i < seq[r].size(); ++i)
      if (seq[r][i] == sum[r] - tar) rval = i + 1;
    printf("YES\n");
    printf("%d %d\n", lval, rval);
    printf("%d %d\n", l, r);
  }
  return 0;
}
