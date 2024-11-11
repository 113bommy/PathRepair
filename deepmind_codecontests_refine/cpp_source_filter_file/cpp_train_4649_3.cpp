#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[333333], p[333333];
int before[333333], a[333333], anum;
int res[333333], rnum;
void doit(int k) {
  int x1 = min(p[k], p[k - 1]);
  if (x1) res[rnum++] = k - 1;
  p[k] -= x1, p[k - 1] += x1;
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) scanf("%I64d", &p[i]);
  for (int i = 1; i < n + 1; i++) {
    ll k1 = dp[max(0, i - 2)] + p[i];
    ll k2 = dp[max(0, i - 3)] + max(p[i], p[i - 1]);
    if (k1 < k2)
      dp[i] = k1, before[i] = max(0, i - 2);
    else
      dp[i] = k2, before[i] = max(0, i - 3);
  }
  int x = n;
  if (dp[n - 1] < dp[n]) x = n - 1;
  for (; x; x = before[x]) a[++anum] = x;
  reverse(a + 1, a + anum + 1);
  for (int i = 1; i < anum + 1; i++) {
    int k = a[i];
    doit(k);
    doit(k + 1);
    if (a[i] - a[i - 1] == 3) {
      doit(k - 1);
    }
  }
  printf("%d\n", rnum);
  for (int i = 0; i < rnum; i++) printf("%d\n", res[i]);
}
