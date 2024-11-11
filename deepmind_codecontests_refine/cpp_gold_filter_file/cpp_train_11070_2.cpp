#include <bits/stdc++.h>
int n, c;
int a[10010], b[10010];
long long lan, ran;
long long chk(long long mi) {
  long long rem = c;
  for (int i = 0; i < n; ++i) {
    double tem = (double)a[i] / b[i] * mi;
    if (tem - rem >= 1.0) return 1;
    rem -= (long long)tem;
  }
  if (rem > 0) return -1;
  return 0;
}
long long bs2(long long le, long long ri, long long tar) {
  while (le < ri) {
    long long mi = (le + ri + 1 >> 1);
    long long val = chk(mi);
    if (val == -1) le = mi;
    if (val == 0) le = mi;
    if (val == 1) ri = mi - 1;
  }
  return le;
}
long long bs1(long long le, long long ri, long long tar) {
  while (le < ri) {
    long long mi = (le + ri >> 1);
    long long val = chk(mi);
    if (val == -1) le = mi + 1;
    if (val == 0) ri = mi;
    if (val == 1) ri = mi;
  }
  return le;
}
int main(void) {
  scanf("%d%d", &n, &c);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
  c -= n;
  if (c < 0) {
    puts("0");
    return 0;
  }
  lan = bs1(1, (1LL << 61), c);
  ran = bs2(1, (1LL << 61), c);
  if (lan == (1LL << 61))
    puts("0");
  else if (ran == (1LL << 61))
    puts("-1");
  else {
    if (chk(lan) == 0 && chk(ran) == 0)
      printf("%I64d\n", ran - lan + 1);
    else
      puts("0");
  }
  return 0;
}
