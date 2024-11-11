#include <bits/stdc++.h>
using namespace std;
int n, k;
int v[300500];
int bit[300500];
void add(int pos) {
  while (pos <= n) {
    bit[pos]++;
    pos += pos & (-pos);
  }
}
int sum(int pos) {
  if (pos < 0) return 0;
  int ret = 1;
  while (pos > 0) {
    ret += bit[pos];
    pos -= pos & (-pos);
  }
  return ret;
}
int seg(int l, int r) { return sum(r) - sum(l - 1); }
int dp[300500];
bool judge(int x) {
  for (int i = 0; i <= n; ++i) bit[i] = 0;
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int ub = i - k;
    int lb = lower_bound(v + 1, v + 1 + n, v[i] - x) - v - 1;
    dp[i] = seg(lb, ub) > 0 ? 1 : 0;
    if (dp[i]) add(i);
  }
  return dp[n] > 0;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
  sort(v + 1, v + 1 + n);
  int lb = -1, ub = v[n] - v[1];
  while (ub > lb + 1) {
    int mid = lb + (ub - lb) / 2;
    if (judge(mid))
      ub = mid;
    else
      lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
