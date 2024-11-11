#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 5;
int readint() {
  int x = 0, f = 1;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    (s = getchar());
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    (s = getchar());
  }
  return x * f;
}
long long Fabs(long long x) {
  if (x < 0) x = -x;
  return x;
}
int a[maxn], b[maxn];
pair<int, int> ans, ans1, ans2;
pair<long long, pair<int, int> > sum[maxn * maxn];
int cnt;
signed main() {
  int n = readint();
  long long sum1 = 0, sum2 = 0;
  for (int i = 1; i <= n; i++) {
    sum1 += (a[i] = readint());
  }
  int m = readint();
  for (int i = 1; i <= m; i++) {
    sum2 += (b[i] = readint());
  }
  if (Fabs(sum1 - sum2) < 1) {
    printf("0\n0");
    return 0;
  }
  bool flag1 = 0, flag2 = 0;
  long long differ = Fabs(sum1 - sum2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long newsum1 = sum1 - a[i] + b[j];
      long long newsum2 = sum2 - b[j] + a[i];
      if (Fabs(newsum1 - newsum2) < differ) {
        flag1 = 1;
        ans = make_pair(i, j);
        differ = Fabs(newsum1 - newsum2);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      sum[++cnt].first = 2ll * (a[i] + a[j]);
      sum[cnt].second = make_pair(i, j);
    }
  }
  long long delta = sum1 - sum2;
  sort(sum + 1, sum + cnt + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      long long tmp = delta + 2ll * (b[i] + b[j]);
      int pos =
          lower_bound(sum + 1, sum + cnt + 1, make_pair(tmp, make_pair(0, 0))) -
          sum;
      for (int k = max(1, pos - 1); k <= min(cnt, pos + 1); k++) {
        long long dif = Fabs(tmp - sum[k].first);
        if (dif < differ) {
          flag2 = 1;
          differ = dif;
          ans1 = make_pair(sum[k].second.first, i);
          ans2 = make_pair(sum[k].second.second, j);
        }
      }
    }
  }
  if (flag2) {
    printf("%lld\n2\n", differ);
    printf("%d %d", ans1.first, ans1.second);
    puts("");
    printf("%d %d", ans2.first, ans2.second);
  } else if (flag1) {
    printf("%lld\n1\n", differ);
    printf("%d %d", ans.first, ans.second);
  } else {
    printf("%lld\n0", differ);
  }
  return 0;
}
