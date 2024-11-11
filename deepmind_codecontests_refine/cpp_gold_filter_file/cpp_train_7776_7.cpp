#include <bits/stdc++.h>
using namespace std;
int dp[2005][10][10][10][10];
int f_dp[10][10][10][10][10][10];
int st[2005], en[2005], n;
int func(int pos, int fir, int sec, int third, int fourth, int e) {
  if (fir == 0 && sec == 0 && third == 0 && fourth == 0) {
    if (e == 0) return 0;
    return abs(pos - e);
  }
  if (f_dp[pos][fir][sec][third][fourth][e] != -1)
    return f_dp[pos][fir][sec][third][fourth][e];
  int ret = 70000000;
  if (fir) {
    ret = min(ret, func(fir, 0, sec, third, fourth, e) + abs(pos - fir) + 1);
  }
  if (sec) {
    ret = min(ret, func(sec, fir, 0, third, fourth, e) + abs(pos - sec) + 1);
  }
  if (third) {
    ret = min(ret, func(third, fir, sec, 0, fourth, e) + abs(pos - third) + 1);
  }
  if (fourth) {
    ret = min(ret, func(fourth, fir, sec, third, 0, e) + abs(pos - fourth) + 1);
  }
  return f_dp[pos][fir][sec][third][fourth][e] = ret;
}
int dp_func(int pos, int fir, int sec, int third, int fourth) {
  if (pos == n) {
    return func(st[pos - 1], fir, sec, third, fourth, 0);
  }
  int v = dp[pos][fir][sec][third][fourth];
  if (dp[pos][fir][sec][third][fourth] != -1)
    return dp[pos][fir][sec][third][fourth];
  int pre = st[pos - 1];
  int f = abs(pre - st[pos]) + 1;
  int ret = 70000000;
  int fs = fir;
  int sc = sec;
  int th = third;
  int ft = fourth;
  if (fir == 0 || sec == 0 || third == 0 || fourth == 0) {
    if (fir == 0)
      fs = en[pos];
    else if (sec == 0)
      sc = en[pos];
    else if (third == 0)
      th = en[pos];
    else
      ft = en[pos];
    ret = min(ret, dp_func(pos + 1, fs, sc, th, ft) + f);
  }
  if (fir) {
    ret = min(ret, dp_func(pos + 1, en[pos], sec, third, fourth) +
                       abs(pre - fir) + abs(st[pos] - fir) + 2);
  }
  if (sec) {
    ret = min(ret, dp_func(pos + 1, fir, en[pos], third, fourth) +
                       abs(pre - sec) + abs(st[pos] - sec) + 2);
  }
  if (third) {
    ret = min(ret, dp_func(pos + 1, fir, sec, en[pos], fourth) +
                       abs(pre - third) + abs(st[pos] - third) + 2);
  }
  if (fourth) {
    ret = min(ret, dp_func(pos + 1, fir, sec, third, en[pos]) +
                       abs(pre - fourth) + abs(st[pos] - fourth) + 2);
  }
  if (fir && sec) {
    ret = min(ret, dp_func(pos + 1, en[pos], 0, third, fourth) +
                       func(pre, fir, sec, 0, 0, st[pos]) + 1);
  }
  if (fir && third) {
    ret = min(ret, dp_func(pos + 1, en[pos], sec, 0, fourth) +
                       func(pre, fir, 0, third, 0, st[pos]) + 1);
  }
  if (fir && fourth) {
    ret = min(ret, dp_func(pos + 1, en[pos], sec, third, 0) +
                       func(pre, fir, 0, 0, fourth, st[pos]) + 1);
  }
  if (sec && third) {
    ret = min(ret, dp_func(pos + 1, fir, en[pos], 0, fourth) +
                       func(pre, 0, sec, third, 0, st[pos]) + 1);
  }
  if (sec && fourth) {
    ret = min(ret, dp_func(pos + 1, fir, en[pos], third, 0) +
                       func(pre, 0, sec, 0, fourth, st[pos]) + 1);
  }
  if (third && fourth) {
    ret = min(ret, dp_func(pos + 1, fir, sec, en[pos], 0) +
                       func(pre, 0, 0, third, fourth, st[pos]) + 1);
  }
  if (fir && sec && third) {
    ret = min(ret, dp_func(pos + 1, 0, 0, en[pos], fourth) +
                       func(pre, fir, sec, third, 0, st[pos]) + 1);
  }
  if (fir && sec && fourth) {
    ret = min(ret, dp_func(pos + 1, 0, 0, third, en[pos]) +
                       func(pre, fir, sec, 0, fourth, st[pos]) + 1);
  }
  if (fir && third && fourth) {
    ret = min(ret, dp_func(pos + 1, 0, sec, 0, en[pos]) +
                       func(pre, fir, 0, third, fourth, st[pos]) + 1);
  }
  if (sec && third && fourth) {
    ret = min(ret, dp_func(pos + 1, fir, 0, en[pos], 0) +
                       func(pre, 0, sec, third, fourth, st[pos]) + 1);
  }
  if (fir && sec && third && fourth) {
    ret = min(ret, dp_func(pos + 1, 0, 0, en[pos], 0) +
                       func(pre, fir, sec, third, fourth, st[pos]) + 1);
  }
  dp[pos][fir][sec][third][fourth] = ret;
  return dp[pos][fir][sec][third][fourth];
}
int main() {
  memset(dp, -1, sizeof dp);
  memset(f_dp, -1, sizeof f_dp);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &st[i], &en[i]);
  }
  int ans = dp_func(1, en[0], 0, 0, 0) + 1 + st[0] - 1;
  cout << ans << endl;
}
