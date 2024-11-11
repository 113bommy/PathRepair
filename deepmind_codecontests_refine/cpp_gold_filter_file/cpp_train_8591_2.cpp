#include <bits/stdc++.h>
inline long long read() {
  long long x = 0;
  char c = getchar(), f = 1;
  for (; c < '0' || '9' < c; c = getchar())
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
inline void write(long long x) {
  static char buf[20];
  int len = 0;
  if (x < 0) putchar('-'), x = -x;
  for (; x; x /= 10) buf[len++] = x % 10 + '0';
  if (!len)
    putchar('0');
  else
    while (len) putchar(buf[--len]);
}
inline void writesp(long long x) {
  write(x);
  putchar(' ');
}
inline void writeln(long long x) {
  write(x);
  putchar('\n');
}
int x[4], y[4], X[4], Y[4];
int L[12];
int ans;
void update(int x0, int y0, int L) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (i == j) continue;
      for (int k = 0; k < 4; k++) {
        if (i == k || j == k) continue;
        for (int l = 0; l < 4; l++) {
          if (i == l || j == l || k == l) continue;
          int flag = 1, cur = 0;
          flag &= (x[i] == x0 || y[i] == y0);
          cur = std::max(cur, std::abs(x[i] - x0) + std::abs(y[i] - y0));
          flag &= (x[j] == x0 + L || y[j] == y0);
          cur = std::max(cur, std::abs(x[j] - x0 - L) + std::abs(y[j] - y0));
          flag &= (x[k] == x0 || y[k] == y0 + L);
          cur = std::max(cur, std::abs(x[k] - x0) + std::abs(y[k] - y0 - L));
          flag &= (x[l] == x0 + L || y[l] == y0 + L);
          cur =
              std::max(cur, std::abs(x[l] - x0 - L) + std::abs(y[l] - y0 - L));
          if (flag && cur < ans) {
            ans = cur;
            X[i] = x0;
            Y[i] = y0;
            X[j] = x0 + L;
            Y[j] = y0;
            X[k] = x0;
            Y[k] = y0 + L;
            X[l] = x0 + L;
            Y[l] = y0 + L;
          }
        }
      }
    }
}
void work() {
  for (int i = 0; i < 4; i++) x[i] = read(), y[i] = read();
  int cntl = 0;
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      L[cntl++] = std::abs(x[i] - x[j]), L[cntl++] = std::abs(y[i] - y[j]);
  ans = 0x3f3f3f3f;
  for (int p = 0; p < cntl; p++) {
    for (int i = 0; i < 4; i++)
      for (int j = i + 1; j < 4; j++) {
        update(x[i], y[j], L[p]);
        update(x[j], y[i], L[p]);
        update(x[i] - L[p], y[j], L[p]);
        update(x[j] - L[p], y[i], L[p]);
        update(x[i], y[j] - L[p], L[p]);
        update(x[j], y[i] - L[p], L[p]);
        update(x[i] - L[p], y[j] - L[p], L[p]);
        update(x[j] - L[p], y[i] - L[p], L[p]);
      }
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++) {
        if (i == j) continue;
        for (int k = 0; k < 4; k++) {
          if (i == k || j == k) continue;
          for (int l = 0; l < 4; l++) {
            if (i == l || j == l || k == l) continue;
            int xa = x[i], ya = y[i], xb = x[j], yb = y[j], xc = x[k],
                yc = y[k], xd = x[l], yd = y[l];
            xb -= L[p];
            yc -= L[p];
            xd -= L[p];
            yd -= L[p];
            if (xa == xb && xb == xc && xc == xd) {
              int mx = std::max(std::max(ya, yb), std::max(yc, yd)),
                  mn = std::min(std::min(ya, yb), std::min(yc, yd));
              if ((mx - mn + 1) / 2 < ans) {
                ans = (mx - mn + 1) / 2;
                X[i] = xa;
                Y[i] = (mx + mn) / 2;
                X[j] = xa + L[p];
                Y[j] = (mx + mn) / 2;
                X[k] = xa;
                Y[k] = (mx + mn) / 2 + L[p];
                X[l] = xa + L[p];
                Y[l] = (mx + mn) / 2 + L[p];
              }
            }
            if (ya == yb && yb == yc && yc == yd) {
              int mx = std::max(std::max(xa, xb), std::max(xc, xd)),
                  mn = std::min(std::min(xa, xb), std::min(xc, xd));
              if ((mx - mn + 1) / 2 < ans) {
                ans = (mx - mn + 1) / 2;
                X[i] = (mx + mn) / 2;
                Y[i] = ya;
                X[j] = (mx + mn) / 2 + L[p];
                Y[j] = ya;
                X[k] = (mx + mn) / 2;
                Y[k] = ya + L[p];
                X[l] = (mx + mn) / 2 + L[p];
                Y[l] = ya + L[p];
              }
            }
          }
        }
      }
  }
  if (ans == 0x3f3f3f3f)
    puts("-1");
  else {
    writeln(ans);
    for (int i = 0; i < 4; i++) writesp(X[i]), writeln(Y[i]);
  }
}
int main() {
  int T = read();
  while (T--) work();
}
