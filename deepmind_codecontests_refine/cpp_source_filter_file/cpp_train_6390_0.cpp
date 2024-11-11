#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 25;
const int modd = 1e9 + 7;
char l[maxn], r[maxn], now[maxn];
int len;
long long minn[maxn], maxx[maxn], sum[maxn], ans[maxn], num[maxn];
long long powe[maxn];
int ycl() {
  minn[0] = 4;
  maxx[0] = 7;
  sum[0] = 11;
  ans[0] = 28;
  num[0] = 2;
  powe[0] = 1;
  for (int i = 1; i < len; i++) powe[i] = powe[i - 1] * 10 % modd;
  for (int i = 1; i < len; i++) {
    long long su = 0;
    su += 2 * ans[i - 1] + (2 * sum[i - 1] - minn[i - 1] - maxx[i - 1]) * 11 %
                               modd * powe[i] % modd;
    su += powe[i] * powe[i] % modd * (num[i - 1] - 1) % modd * 65;
    su += (4 * powe[i] + maxx[i - 1]) % modd *
          ((7 * powe[i] + minn[i - 1]) % modd) % modd;
    su %= modd;
    if (su < 0) su += modd;
    ans[i] = su;
    minn[i] = (4 * powe[i] + minn[i - 1]) % modd;
    maxx[i] = (7 * powe[i] + maxx[i - 1]) % modd;
    sum[i] = powe[i] * num[i - 1] % modd * 11 % modd + sum[i - 1] * 2;
    sum[i] %= modd;
    num[i] = num[i - 1] * 2 % modd;
  }
  return 0;
}
int done() {
  long long gh = 0;
  long long anss = 0;
  for (int i = 0; i < len; i++)
    if (now[i] == '4')
      gh = (gh * 10 + 4) % modd;
    else {
      long long ls = (gh * 10 + 4) % modd;
      gh = (gh * 10 + 7) % modd;
      int wz = len - i - 1;
      if (wz == 0) {
        anss += ls * gh % modd;
        anss %= modd;
      } else {
        anss += ls * powe[wz] % modd *
                (sum[wz - 1] * 2 - minn[wz - 1] - maxx[wz - 1]) % modd;
        anss += ls * ls % modd * powe[wz] % modd * powe[wz] % modd *
                (num[wz - 1] - 1) % modd;
        anss += ans[wz - 1];
        anss += (ls * powe[wz] % modd + maxx[wz - 1]) % modd *
                ((gh * powe[wz] % modd + minn[wz - 1]) % modd) % modd;
        anss %= modd;
      }
    }
  if (anss < 0) anss += modd;
  return anss;
}
int main() {
  scanf("%s", l);
  scanf("%s", r);
  len = strlen(l);
  ycl();
  memcpy(now, r, sizeof(r));
  int aans = done();
  memcpy(now, l, sizeof(l));
  aans -= done();
  printf("%I64d\n", (aans + modd) % modd);
  return 0;
}
