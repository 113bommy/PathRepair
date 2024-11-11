#include <bits/stdc++.h>
using namespace std;
inline int Read() {
  char c = getchar();
  int num = 0;
  while ('0' > c || c > '9') c = getchar();
  while ('0' <= c && c <= '9') num = num * 10 + c - '0', c = getchar();
  return (num);
}
int tot, n, m, a, b, p;
long double sum, X[15010], ans[15010], d;
struct Poi {
  long double x, y;
} q[15010];
int main() {
  n = Read(), m = Read(), a = Read(), b = Read();
  for (int i = 1; i <= n; i++) {
    double x = Read();
    if (i == 1) {
      q[++tot] = (Poi){1., 2 * (1 - x)};
      q[++tot] = (Poi){1e9, 2 * (1e9 - x)};
    } else {
      for (int j = 1; j <= p; j++) q[j].x += a;
      for (int j = tot; j > p; j--) q[j + 2] = (Poi){q[j].x + b, q[j].y};
      q[p + 1] = (Poi){d + a, 0};
      q[p + 2] = (Poi){d + b, 0}, tot += 2;
      while (q[tot - 1].x - 1e9 >= -1e-9) tot--;
      for (int j = 1; j <= tot; j++) q[j].y += 2 * (q[j].x - x);
    }
    if (q[1].y > 0) {
      p = 0, d = q[1].x;
    } else {
      for (p = 1; p < tot; p++)
        if (q[p].y <= 0 && q[p + 1].y >= 0) break;
      d = q[p + 1].x -
          q[p + 1].y * (q[p + 1].x - q[p].x) / (q[p + 1].y - q[p].y);
    }
    ans[i] = d, X[i] = x;
  }
  ans[n] = min(ans[n], (long double)m);
  for (int i = n - 1; i; i--) {
    if (ans[i + 1] - ans[i] < a) ans[i] = ans[i + 1] - a;
    if (ans[i + 1] - ans[i] > b) ans[i] = ans[i + 1] - b;
  }
  for (int i = 1; i <= n; i++) {
    printf("%.9lf ", (double)ans[i]);
    sum = sum + (ans[i] - X[i]) * (ans[i] - X[i]);
  }
  puts("");
  printf("%.9lf\n", (double)sum);
}
