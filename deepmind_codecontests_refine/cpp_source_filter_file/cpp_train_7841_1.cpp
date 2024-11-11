#include <bits/stdc++.h>
int n, f[100000], prim[100000], primNum = 9592;
void initial() {
  int i, j, rt;
  rt = (int)sqrt(100000);
  for (i = 0; i < 100000; i++) f[i] = 1;
  f[0] = f[1] = 0;
  for (i = 2; i <= rt; i++)
    if (f[i])
      for (j = i * i; j < 100000; j += i) f[j] = 0;
  j = 0;
  for (i = 0; i < 100000; i++)
    if (f[i]) prim[j++] = i;
}
int isBigPrim(int n) {
  int i, flag;
  flag = 1;
  for (i = 0; i < primNum; i++)
    if (n % prim[i] == 0) {
      flag = 0;
      break;
    }
  return flag;
}
int main() {
  initial();
  int i, j, res;
  while (scanf("%d", &n) == 1) {
    if (isBigPrim(n)) {
      printf("%d\n", n + 1);
    } else {
      res = n;
      while (n > 1) {
        for (i = 0; i < primNum && prim[i] <= n; i++)
          if (n % prim[i] == 0) {
            n /= prim[i];
            res += n;
            i--;
            continue;
          }
        if (i == primNum) {
          res += n + 1;
          break;
        }
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
