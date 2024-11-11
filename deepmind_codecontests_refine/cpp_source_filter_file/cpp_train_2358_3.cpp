#include <bits/stdc++.h>
using namespace std;
inline long long Get_Int() {
  char x = getchar();
  long long num = 0, bj = 1;
  while (x < '0' || x > '9') {
    if (x == '-') bj = -1;
    x = getchar();
  }
  while (x >= '0' && x <= '9') {
    num = num * 10 + x - '0';
    x = getchar();
  }
  return num * bj;
}
long long s = 0, x, y, opt, Q, i, j, k, m, n, ans = 0, cnt = 1, prt[400005][27],
          Sum[400005][27], v[40005];
void ST(long long x, long long fa) {
  long long y = fa;
  for (i = 25; i >= 0; i--)
    if (prt[y][i] != 0 && v[prt[y][i]] < v[x]) {
      y = prt[y][i];
    }
  if (v[fa] >= v[x]) {
    prt[x][0] = fa;
    Sum[x][0] = v[fa];
  } else {
    prt[x][0] = prt[y][0];
    Sum[x][0] = v[prt[y][0]];
  }
  for (long long i = 1; i <= 25; i++)
    if (prt[x][i - 1] != 0) {
      prt[x][i] = prt[prt[x][i - 1]][i - 1];
      Sum[x][i] = Sum[x][i - 1] + Sum[prt[x][i - 1]][i - 1];
    }
}
int main() {
  Q = Get_Int();
  prt[1][0] = 0;
  v[1] = 0;
  for (k = 1; k <= Q; k++) {
    opt = Get_Int();
    if (opt == 1) {
      x = Get_Int() ^ ans;
      y = Get_Int() ^ ans;
      ++cnt;
      v[cnt] = y;
      ST(cnt, x);
    } else {
      x = Get_Int() ^ ans;
      y = Get_Int() ^ ans;
      s = v[x];
      ans = 1;
      if (y == 0 && 0 == 1) {
        ans = 1;
      } else if (s > y)
        ans = 0;
      else {
        for (i = 25; i >= 0; i--)
          if (prt[x][i] != 0 && s + Sum[x][i] <= y) {
            ans += (1 << i);
            s += Sum[x][i];
            x = prt[x][i];
          }
      }
      printf("%I64d\n", ans);
    }
  }
  return 0;
}
