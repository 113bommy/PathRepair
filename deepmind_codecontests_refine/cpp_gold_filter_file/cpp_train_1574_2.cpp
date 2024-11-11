#include <bits/stdc++.h>
int init_loyal[10] = {0};
int level[10] = {0};
int n_s = 0;
int n_c = 0;
double ans = 0;
int A = 0;
int candies[10] = {0};
int now_loyal[10] = {0};
int bit_cnt(int mask) {
  int ret = 0;
  while (mask > 0) {
    if (mask & 1) ret++;
    mask >>= 1;
  }
  return ret;
}
void get_prob() {
  int mask = 0;
  int i = 0;
  double p = 0;
  double to_ans = 0;
  for (mask = 0; mask < (1 << n_s); mask++) {
    p = 1;
    for (i = 0; i < n_s; i++) {
      if ((mask & (1 << i)) == 0)
        p *= ((100. - now_loyal[i]) / 100.);
      else
        p *= (now_loyal[i] / 100.);
    }
    if (bit_cnt(mask) * 2 > n_s)
      to_ans += p;
    else {
      double B = 0;
      for (i = 0; i < n_s; i++)
        if ((mask & (1 << i)) == 0) B += level[i];
      p *= (A / (A + B));
      to_ans += p;
    }
  }
  if (to_ans > ans) ans = to_ans;
}
void rec(int dp, int c_left) {
  if (dp >= n_s) {
    get_prob();
    return;
  }
  for (candies[dp] = 0; candies[dp] <= c_left; candies[dp]++) {
    now_loyal[dp] = init_loyal[dp] + candies[dp] * 10;
    if (now_loyal[dp] > 100) now_loyal[dp] = 100;
    rec(dp + 1, c_left - candies[dp]);
  }
}
int main() {
  scanf("%d%d%d", &n_s, &n_c, &A);
  int i = 0;
  for (i = 0; i < n_s; i++) {
    scanf("%d%d", &level[i], &init_loyal[i]);
  }
  rec(0, n_c);
  printf("%.10lf", ans);
  return 0;
}
