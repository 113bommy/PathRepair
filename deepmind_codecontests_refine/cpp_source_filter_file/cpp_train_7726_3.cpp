#include <bits/stdc++.h>
using namespace std;
int a[100], sum[40], i, j, m, k, l, T, ans, maxn;
long long n, num, now;
void query(long long x) {
  int m = 0;
  while (x) {
    if (x & 1) a[m]++, maxn = m;
    x /= 2;
    m++;
  }
}
void qy(int x) {
  int m = 0;
  while (x) {
    if (x & 1) sum[m]++;
    x /= 2;
    m++;
  }
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%I64d%d", &n, &m);
    memset(a, 0, sizeof a);
    memset(sum, 0, sizeof sum);
    num = 0;
    query(n);
    ans = 0;
    for (i = 1; i <= m; i++) {
      int x;
      scanf("%d", &x);
      qy(x);
      num += x;
    }
    if (num < n)
      printf("-1\n");
    else {
      now = 0;
      for (i = 0; i <= m; i++) {
        now += 1ll * sum[i] * (1ll << i);
        if (a[i] == 1) {
          if (now < (1ll << i)) {
            for (j = i + 1; j <= 32; j++)
              if (sum[j] > 0) {
                ans += j - i;
                sum[j]--;
                now += 1ll * ((1ll << (j - i)) - 1) * (1ll << i);
                break;
              }
          } else
            now -= (1ll << i);
        }
      }
      printf("%d\n", ans);
    }
  }
}
