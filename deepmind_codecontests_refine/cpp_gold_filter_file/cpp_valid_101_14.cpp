#include <bits/stdc++.h>
inline long long read() {
  long long num = 0, f = 1;
  char c = getchar();
  while (c < 48 || c > 57) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c > 47 && c < 58) num = num * 10 + (c ^ 48), c = getchar();
  return num * f;
}
inline long long re1d() {
  char c = getchar();
  while (c < 48 || c > 49) c = getchar();
  return c & 1;
}
inline long long min(long long a, long long b) { return a > b ? b : a; }
inline long long max(long long a, long long b) { return a < b ? b : a; }
long long X[300005], Y[300005], x[300005], y[300005], xx[300005], yy[300005];
std::map<long long, long long> mpx[300005], mpy[300005];
long long sumx[300005], sumy[300005];
signed main() {
  long long T = read();
  for (long long i = 1; i <= (T); i++) {
    long long n = read(), m = read(), k = read();
    for (long long i = 1; i <= (n); i++) {
      X[i] = xx[i] = read();
    }
    for (long long i = 1; i <= (m); i++) {
      Y[i] = yy[i] = read();
    }
    for (long long i = 1; i <= (n); i++) {
      mpx[i].clear();
      sumx[i] = 0;
    }
    for (long long i = 1; i <= (m); i++) {
      mpy[i].clear();
      sumy[i] = 0;
    }
    long long ans = 0;
    for (long long i = 1; i <= (k); i++) {
      x[i] = read(), y[i] = read();
      long long dx = std::lower_bound(X + 1, X + 1 + n, x[i]) - X;
      long long dy = std::lower_bound(Y + 1, Y + 1 + m, y[i]) - Y;
      if (X[dx] == x[i] && Y[dy] == y[i]) continue;
      if (X[dx] != x[i]) {
        sumx[dx]++;
        mpx[dx][dy]++;
        ans += (sumx[dx] - mpx[dx][dy]);
      } else {
        sumy[dy]++;
        mpy[dy][dx]++;
        ans += (sumy[dy] - mpy[dy][dx]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
