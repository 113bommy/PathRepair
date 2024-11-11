#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int read() {
  int x;
  scanf("%d", &x);
  return x;
}
int query[N], peo[N], lp;
int ask(int x, int y, int z) {
  printf("? %d %d %d\n", x, y, z);
  fflush(stdout);
  int p = read();
  return p;
}
int main() {
  int one, zero, cheat, honest, t, n, i, j;
  t = read();
  while (t--) {
    lp = 0;
    n = read();
    for (i = 1; i <= n; i += 3) {
      query[i] = ask(i, i + 1, i + 2);
      if (query[i] == 1)
        one = i;
      else
        zero = i;
    }
    int tmp1 = ask(one + 1, one + 2, zero);
    int tmp2 = ask(one + 2, zero, zero + 1);
    if (query[one] != tmp1) {
      if (tmp1 == 1)
        cheat = one, honest = zero;
      else
        honest = zero, cheat = one;
    } else if (tmp1 != tmp2) {
      if (tmp2 == 1)
        cheat = one + 1, honest = zero + 1;
      else
        honest = one + 1, cheat = zero + 1;
    } else if (tmp2 != query[zero]) {
      if (query[zero] == 1)
        cheat = one + 2, honest = zero + 2;
      else
        honest = one + 2, cheat = zero + 2;
    }
    for (i = 1; i <= n; i += 3) {
      if ((i <= cheat && cheat <= i + 2) || (i <= honest && honest <= i + 2)) {
        for (j = i; j <= i + 2; j++)
          if (j == cheat || j == honest)
            continue;
          else {
            tmp1 = ask(j, honest, cheat);
            if (!tmp1) peo[++lp] = j;
          }
        continue;
      }
      if (query[i] == 0) {
        tmp1 = ask(i, i + 1, honest);
        if (tmp1 == 0) {
          peo[++lp] = i, peo[++lp] = i + 1;
          tmp2 = ask(i + 2, honest, cheat);
          if (!tmp2) peo[++lp] = i + 2;
        } else {
          tmp2 = ask(i, honest, cheat);
          if (tmp2)
            peo[++lp] = i + 1;
          else
            peo[++lp] = i;
          peo[++lp] = i + 2;
        }
      } else {
        tmp1 = ask(i, i + 1, cheat);
        if (tmp1 == 1) {
          tmp2 = ask(i + 2, honest, cheat);
          if (!tmp2) peo[++lp] = i + 2;
        } else {
          tmp2 = ask(i, honest, cheat);
          if (tmp2)
            peo[++lp] = i + 1;
          else
            peo[++lp] = i;
        }
      }
    }
    printf("! %d ", lp + 1);
    for (i = 1; i <= lp; i++) printf("%d ", peo[i]);
    printf("%d\n", cheat);
    fflush(stdout);
  }
  return 0;
}
