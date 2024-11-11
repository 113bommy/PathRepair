#include <bits/stdc++.h>
using namespace std;
int n, size[200010] = {0}, dp[200010][5] = {0};
vector<int> w[200010];
int dpMax(int, int);
int dpMin(int, int);
int child(int x) {
  int ret = 0;
  for (int i = 0; i < w[x].size(); i++) ret += child(w[x][i]);
  return size[x] = ret + !w[x].size();
}
int dpMax(int x, int t) {
  if (dp[x][t]) return dp[x][t];
  int ret1, ret2;
  ret1 = ret2 = !w[x].size();
  for (int i = 0; i < w[x].size(); i++) {
    if (!t)
      ret1 = max(ret1, size[x] - size[w[x][i]] + dpMin(w[x][i], 0));
    else
      ret2 += (dpMin(w[x][i], 1));
  }
  return dp[x][t] = (!t ? ret1 : ret2);
}
int dpMin(int x, int t) {
  if (dp[x][t]) return dp[x][t];
  int ret1, ret2;
  ret1 = 1;
  ret2 = 1 + (1 << 28) * w[x].size();
  for (int i = 0; i < w[x].size(); i++) {
    ret1 += (dpMax(w[x][i], 0) - 1);
    ret2 = min(ret2, (dpMax(w[x][i], 1)));
  }
  return dp[x][t] = (!t ? ret1 : ret2);
}
int main() {
  scanf("%d", &n);
  for (int i = 0, a, b; i < n - 1; i++) {
    scanf("%d%d", &a, &b);
    w[a].push_back(b);
  }
  child(1);
  printf("%d %d\n", dpMax(1, 0), dpMax(1, 1));
  return 0;
}
