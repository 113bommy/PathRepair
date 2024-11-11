#include <bits/stdc++.h>
using namespace std;
int IN() {
  int x = 0, f = 0, ch;
  for (; (ch = getchar()) < '0' || ch > '9';) f = (ch == '-');
  for (; ch >= '0' && ch <= '9'; (ch = getchar())) x = x * 10 + ch - '0';
  return f ? -x : x;
}
int A[25];
long long F[25][2][2];
long long Dp(int s) {
  for (int i = 0, lim = 20; i <= lim; i++)
    for (int a = 0, lim = 1; a <= lim; a++)
      for (int b = 0, lim = 1; b <= lim; b++) F[i][a][b] = 0;
  F[0][1][0] = 1;
  for (int i = 1, lim = 20; i <= lim; i++)
    for (int a = 0, lim = 1; a <= lim; a++)
      for (int b = 0, lim = 1; b <= lim; b++) {
        long long v = F[i - 1][a][b];
        if (!v) continue;
        for (int c = 0, lim = s; c <= lim; c++) {
          if (4 * (i - 1) <= s && s < 4 * i) {
            if ((c >> (s - 4 * (i - 1))) % 2 == 0) continue;
          }
          F[i][c < A[i] || (c == A[i] && a)][b || c == s] += v;
        }
      }
  return F[20][1][1];
}
long long Cal(long long M) {
  if (M <= 0) return 0;
  for (int i = 1, lim = 20; i <= lim; i++) A[i] = 0;
  for (int i = 1, lim = 20; i <= lim; i++) A[i] = M & 15, M >>= 4;
  long long ret = 0;
  for (int s = 0, lim = 15; s <= lim; s++) ret += Dp(s);
  return ret;
}
int main(int argc, char* argv[]) {
  for (int Q = IN(); Q--;) {
    long long x, y;
    scanf("%llx%llx", &x, &y);
    printf("%lld\n", Cal(y) - Cal(x - 1));
  }
  return 0;
}
