#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const long long MOD = 1e9 + 7;
int n;
char s[MAXN];
long long ans[15], alen[15];
string c[MAXN];
long long xx[MAXN];
long long getx(long long x) {
  long long res = 1;
  int k = 0;
  while (x > 0) {
    if (x & 1) {
      res *= xx[k];
      if (res > MOD) res %= MOD;
    }
    x >>= 1;
    k++;
  }
  return res;
}
int main() {
  xx[0] = 10;
  for (int i = 1; i <= 100000; i++) {
    xx[i] = xx[i - 1] * xx[i - 1];
    if (xx[i] > MOD) xx[i] %= MOD;
  }
  while (scanf("%s%d", s, &n) != EOF) {
    char cc[MAXN];
    for (int i = 1; i <= n; i++) {
      scanf("%s", cc);
      c[i] = cc;
    }
    for (int i = 0; i <= 9; i++) ans[i] = i, alen[i] = 1;
    for (int i = n; i >= 1; i--) {
      int len = c[i].length(), k;
      long long v = 0, l = 0;
      for (int j = 3; j < len; j++) {
        k = c[i][j] - '0';
        v = v * getx(alen[k]) + ans[k];
        if (v > MOD) v %= MOD;
        l += alen[k];
        if (l > MOD - 1) l -= MOD + 1;
      }
      k = c[i][0] - '0';
      ans[k] = v;
      alen[k] = l;
    }
    int len = strlen(s);
    long long res = 0;
    for (int i = 0; i <= len - 1; i++) {
      int k = s[i] - '0';
      res = res * getx(alen[k]) + ans[k];
      if (res > MOD) res %= MOD;
    }
    printf("%I64d\n", res);
  }
  return 0;
}
