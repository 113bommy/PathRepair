#include <bits/stdc++.h>
using namespace std;
long long fn(int left);
void trace(int left, long long with_me, int nw);
long long dp[55 + 5], k;
int n;
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d %lld", &n, &k);
  fn(n);
  trace(n, 0, 0);
  printf("\n");
  return 0;
}
void trace(int left, long long with_me, int nw) {
  if (left == 0) return;
  int d = 0;
  for (int i = 1; i <= 2; i++) {
    if (i % 2 && i != 1) continue;
    if (with_me + fn(left - i) >= k)
      break;
    else
      with_me += fn(left - i), d = i;
  }
  d++;
  bool g = 1;
  if (left == n) g = 0;
  for (int i = nw + d - 1; i >= nw; i--) {
    if (g)
      printf(" ");
    else
      g = 1;
    printf("%d", i + 1);
  }
  trace(left - d, with_me, nw + d);
}
long long fn(int left) {
  long long& ret = dp[left];
  if (ret != -1) return ret;
  ret = 0;
  if (left == 0) {
    ret = 1;
    return ret;
  }
  for (int i = 1; i <= 2; i++) {
    if (i % 2 && i != 1) continue;
    ret += fn(left - i);
  }
  return ret;
}
