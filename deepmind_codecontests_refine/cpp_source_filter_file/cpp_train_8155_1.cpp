#include <bits/stdc++.h>
using namespace std;
int n, re;
int s[1005], sn;
int res[1005], resn;
int get(int a, int b) {
  int i, j, k, t1, t2, t3;
  t3 = b;
  t1 = 0;
  sn = 0;
  while (b != 0) {
    t1 += a / b;
    s[sn] = a / b;
    ++sn;
    k = a % b;
    a = b;
    b = k;
  }
  if (t1 != n || a != 1)
    return 0;
  else {
    t2 = 0;
    for (i = sn - 1; i != -1; --i) {
      t2 += (s[i] - 1);
    }
    if (t2 < re) {
      re = t2;
      resn = sn;
      for (i = 0; i != sn; ++i) {
        res[i] = s[sn - i - 1];
      }
    }
  }
  return re;
}
int main() {
  int i, j, k, t1, t2, t3;
  while (scanf("%d%d", &n, &t1) != EOF) {
    re = 99999999;
    if (n == 0 && t1 == 1) {
      printf("0\n");
      continue;
    } else if (n == 1 && t1 == 1) {
      printf("1\nT\n");
      continue;
    } else if (n == 0 || t1 == 1 || t1 == 0) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    for (i = 1; i != t1; ++i) {
      get(t1, i);
    }
    if (re == 99999999) {
      printf("IMPOSSIBLE\n");
      continue;
    } else {
      if (res[0] != 1) {
        printf("%d\n", re - 1);
        t1 = 0;
        printf("TB");
        res[0] -= 2;
      } else {
        printf("%d\n", re);
        t1 = 0;
      }
      for (i = 0; i != resn; ++i) {
        while (res[i] > 0) {
          if (t1 == 0)
            printf("B");
          else if (t1 == 1)
            printf("T");
          --res[i];
        }
        t1 = (t1 + 1) % 2;
      }
      printf("\n");
    }
  }
  return 0;
}
