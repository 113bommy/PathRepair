#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
struct TnT {
  int sta, cau, flag;
  long long val;
} a[M << 1];
bool cmp(TnT x, TnT y) {
  if (x.sta == y.sta) return x.val < y.val;
  return x.sta < y.sta;
}
long long dp[M];
int main() {
  int n;
  long long x;
  scanf("%d%lld", &n, &x);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    int l, r;
    long long c;
    scanf("%d%d%lld", &l, &r, &c);
    a[cnt].sta = l, a[cnt].flag = 1, a[cnt].cau = r - l + 1, a[cnt].val = c;
    a[++cnt].sta = r, a[cnt].flag = -1, a[cnt].cau = r - l + 1, a[cnt].val = c;
    cnt++;
  }
  sort(a, a + cnt, cmp);
  for (int i = 0; i < M; i++) dp[i] = 1000000000000;
  long long ans = 1000000000000;
  for (int i = 0; i < cnt; i++) {
    if (a[i].flag == 1) {
      long long sum = x - a[i].cau;
      if (sum >= 0) {
        if (dp[sum] < 1000000000000) ans = min(ans, a[i].val + dp[sum]);
      }
    } else {
      dp[a[i].cau] = min(dp[a[i].cau], a[i].val);
    }
  }
  if (ans < 1000000000000)
    printf("%lld\n", ans);
  else
    printf("-1\n");
  return 0;
}
