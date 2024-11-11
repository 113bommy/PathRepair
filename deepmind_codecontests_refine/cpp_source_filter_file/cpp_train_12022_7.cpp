#include <bits/stdc++.h>
using namespace std;
double dp[7][2][3];
int vis[7][2][3], v;
int st[9], en[9];
double dp_func(int pos, int boro, int eq) {
  if (pos == 0) {
    if (eq && boro == 1) return v;
    if (eq >= 2) return v;
    return 0;
  }
  double l, k, r, d, ret = 0;
  if (vis[pos][boro][eq] != 0) return dp[pos][boro][eq];
  if (st[pos] < v) {
    l = st[pos];
    k = min(v - 1, en[pos]);
    r = k - l + 1;
    d = en[pos] - st[pos] + 1;
    ret = ret + (dp_func(pos - 1, boro, eq) * r);
  }
  if (st[pos] <= v && en[pos] >= v) {
    d = en[pos] - st[pos] + 1;
    ret = ret + dp_func(pos - 1, boro, min(2, eq + 1));
  }
  if (boro == 0 && en[pos] > v) {
    d = en[pos] - st[pos] + 1;
    k = en[pos];
    l = max(st[pos], v + 1);
    r = k - l + 1;
    ret = ret + (dp_func(pos - 1, 1, eq) * r);
  }
  d = en[pos] - st[pos] + 1;
  ret = ret / d;
  vis[pos][boro][eq] = 1;
  return dp[pos][boro][eq] = ret;
}
int main() {
  int i, j, k, l, m, n;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d%d", &st[i], &en[i]);
  }
  double sum = 0;
  for (int i = 1; i <= 10000; i++) {
    memset(vis, 0, sizeof vis);
    v = i;
    sum += dp_func(n, 0, 0);
  }
  printf("%.8f\n", sum);
}
