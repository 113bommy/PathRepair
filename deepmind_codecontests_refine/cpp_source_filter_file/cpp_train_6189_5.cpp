#include <bits/stdc++.h>
const int LEN = 8;
const int MASK = (1 << LEN);
const int maxn = 220;
double f[2][LEN + 1][MASK][2][maxn + 1];
int old, now;
double result;
int n, original;
double add1, time2;
void init() {
  int P;
  scanf("%d%d%d", &original, &n, &P);
  time2 = P / 100.0;
  add1 = 1 - time2;
}
int numlen(int x) {
  int len = 0;
  if (x == 0) return 1;
  while (x) {
    ++len;
    x = (x >> 1);
  }
  return len;
}
int count0(int x) {
  int g0 = 0;
  while ((x > 0) && ((x & 1) == 0)) {
    x = (x >> 1);
    ++g0;
  }
  return g0;
}
int count1(int x) {
  int g1 = 0;
  while ((x > 0) && ((x & 1) == 1)) {
    x = (x >> 1);
    ++g1;
  }
  return g1;
}
inline void calc(int &d, int &plen, int nd, int &d2, int &plen2) {
  if (nd == d) {
    d2 = d;
    plen2 = plen + 1;
  } else {
    d2 = nd;
    plen2 = 1;
  }
}
void work() {
  int i, len, num, digit, prelen, tmp, len2, num2, digit2, prelen2;
  now = 0;
  for (len = 1; len <= LEN; ++len)
    for (num = 0; num < (1 << len); ++num)
      for (digit = 0; digit < 2; ++digit)
        for (prelen = 0; prelen <= maxn; ++prelen)
          f[now][len][num][digit][prelen] = 0;
  if (numlen(original) <= LEN)
    f[now][numlen(original)][original][0][0] = 1;
  else {
    tmp = original >> LEN;
    if ((tmp & 1) == 0)
      f[now][LEN][original & ((1 << LEN) - 1)][0][count0(tmp)] = 1;
    else
      f[now][LEN][original & ((1 << LEN) - 1)][1][count1(tmp)] = 1;
  }
  for (i = 1; i <= n; ++i) {
    old = now;
    now = 1 - now;
    for (len = 1; len <= LEN; ++len)
      for (num = 0; num < (1 << len); ++num)
        for (digit = 0; digit < 2; ++digit)
          for (prelen = 0; prelen <= maxn; ++prelen)
            f[now][len][num][digit][prelen] = 0;
    for (len = 1; len <= LEN; ++len)
      for (num = 0; num < (1 << len); ++num)
        for (digit = 0; digit < 2; ++digit)
          for (prelen = 0; prelen <= maxn; ++prelen)
            if (f[old][len][num][digit][prelen] > 1e-16) {
              len2 = len;
              num2 = num;
              digit2 = digit;
              prelen2 = prelen;
              if (len < LEN) {
                len2 = len + 1;
                num2 = num << 1;
              } else {
                if (num & (1 << (LEN - 1)))
                  calc(digit, prelen, 1, digit2, prelen2);
                else
                  calc(digit, prelen, 0, digit2, prelen2);
                num2 = ((num << 1) & ((1 << LEN) - 1));
              }
              f[now][len2][num2][digit2][prelen2] +=
                  f[old][len][num][digit][prelen] * time2;
              len2 = len;
              num2 = num;
              digit2 = digit;
              prelen2 = prelen;
              if (num + 1 < (1 << len))
                num2 = num + 1;
              else {
                if (len < LEN) {
                  num2 = num + 1;
                  len2 = len + 1;
                } else {
                  num2 = 0;
                  if (digit == 0) {
                    digit2 = 1;
                    prelen2 = 1;
                  } else {
                    digit2 = 0;
                    prelen2 = prelen;
                  }
                }
              }
              f[now][len2][num2][digit2][prelen2] +=
                  f[old][len][num][digit][prelen] * add1;
            }
  }
}
void output() {
  int i, j, d, k;
  int g0;
  result = 0;
  for (i = 1; i <= LEN; ++i)
    for (j = 0; j < (1 << i); ++j)
      for (d = 0; d < 2; ++d)
        for (k = 0; k <= maxn; ++k) {
          if (j == 0) {
            g0 = i;
            if (d == 0) g0 += k;
          } else
            g0 = count0(j);
          result += f[now][i][j][d][k] * g0;
        }
  printf("%.10lf\n", result);
}
int main() {
  init();
  work();
  output();
  return 0;
}
