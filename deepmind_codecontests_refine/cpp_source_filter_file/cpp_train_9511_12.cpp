#include <bits/stdc++.h>
double comb[1001][1001];
double dp[1001][1001];
int obj[1001][1001];
bool flag[1001];
int cnt[1001], cnt2[1001];
int price[1001];
int n, m, s, k, p, q;
int main() {
  int i, j;
  comb[0][0] = 1.;
  for (i = 1; i <= 1000; i++) {
    comb[i][0] = 1.;
    for (j = 1; j < i; j++) {
      comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
    }
    comb[i][i] = 1.;
  }
  scanf("%d%d", &m, &n);
  s = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", cnt + i);
    for (j = 0; j < cnt[i]; j++) {
      scanf("%d", &obj[i][j]);
      price[s] = obj[i][j];
      ++s;
    }
  }
  std::sort(price, price + s);
  k = price[s - m];
  p = 0;
  for (i = 0; i < n; i++) {
    flag[i] = false;
    cnt2[i] = 0;
    for (j = 0; j < cnt[i]; j++) {
      if (obj[i][j] == k) {
        flag[i] = true;
        p++;
      }
      if (obj[i][j] > k) {
        cnt2[i]++;
      }
    }
  }
  q = 0;
  for (i = s - m; i < s && price[i] == k; i++) {
    q++;
  }
  dp[0][0] = 1.;
  for (i = 1; i <= n; i++) {
    for (j = 0; j <= s; j++) {
      dp[i][j] = dp[i - 1][j] / comb[cnt[i - 1]][cnt2[i - 1]];
      if (flag[i - 1]) {
        dp[i][j] += dp[i - 1][j - 1] / comb[cnt[i - 1]][cnt2[i - 1] + 1];
      }
    }
  }
  printf("%.9lf\n", dp[n][q] / comb[p][q]);
  return 0;
}
