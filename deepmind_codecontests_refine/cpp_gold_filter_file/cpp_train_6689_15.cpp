#include <bits/stdc++.h>
using namespace std;
int f(long long i, long long j) {
  if (j & 1) return (i & 1) == 0;
  if (i > j / 2) return i & 1;
  if (i > j / 4) return 1;
  return f(i, j / 4);
}
int g(long long i, long long j) {
  if (i > j / 2) return 1;
  return f(i, j / 2);
}
const int N = 1e5 + 10;
long long s[N], e[N];
int main() {
  int t, fi = 1, se = 0, win, lose;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    win = lose = 0;
    scanf("%I64d%I64d", &s[i], &e[i]);
    if (fi) win |= f(s[i], e[i]), lose |= g(s[i], e[i]);
    if (se) win |= (f(s[i], e[i]) ^ 1), lose |= (g(s[i], e[i]) ^ 1);
    se = win, fi = lose;
  }
  printf("%d %d\n", win, lose);
  return 0;
}
