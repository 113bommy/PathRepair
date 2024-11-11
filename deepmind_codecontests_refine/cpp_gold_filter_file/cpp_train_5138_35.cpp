#include <bits/stdc++.h>
using namespace std;
int k[5010], tot[5010];
int now[5010], x[5010], y[5010], m[5010];
int n, sum, ans0, cnt, cnta;
int ans[200010][2];
pair<int, int> tmp[200010];
int a[5010][5010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d%d", &k[i], &a[i][1], &x[i], &y[i], &m[i]);
    if (k[i] <= 5000) {
      for (int j = 2; j <= k[i]; j++) {
        a[i][j] = (((long long)a[i][j - 1] * x[i]) % m[i] + y[i]) % m[i];
      }
    }
    sum += k[i];
    tot[i] = 1;
    a[i][k[i] + 1] = (int)1e9 + 1;
  }
  if (sum <= 200000) {
    while (true) {
      cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (tot[i] == k[i] + 1) continue;
        for (; tot[i] <= k[i]; tot[i]++) {
          tmp[++cnt] = pair<int, int>(a[i][tot[i]], i);
          if (a[i][tot[i]] > a[i][tot[i] + 1]) {
            tot[i]++;
            break;
          }
        }
      }
      if (cnt == 0) break;
      ans0++;
      stable_sort(tmp + 1, tmp + 1 + cnt);
      for (int i = 1; i <= cnt; i++) {
        cnta++;
        ans[cnta][0] = tmp[i].first;
        ans[cnta][1] = tmp[i].second;
      }
    }
  }
  printf("%d\n", ans0 - 1);
  if (sum <= 200000) {
    for (int i = 1; i <= cnta; i++) {
      printf("%d %d\n", ans[i][0], ans[i][1]);
    }
  }
  return 0;
}
