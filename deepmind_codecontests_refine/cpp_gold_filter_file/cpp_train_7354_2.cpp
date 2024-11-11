#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return x * f;
}
const int N = 2000010;
long long T;
int a[N][2], x[N], a0[N], a1[N], lx, p[N][2], tans[N], tans2[N], cnt[N],
    tans3[N];
long long f[N][2];
int main() {
  int n = read(), m0 = read(), m1 = read();
  T = read();
  for (int i = 1; i <= m0; ++i) x[++lx] = a0[i] = read();
  for (int i = 1; i <= m1; ++i) x[++lx] = a1[i] = read();
  x[++lx] = 1;
  sort(x + 1, x + lx + 1);
  lx = unique(x + 1, x + lx + 1) - x - 1;
  x[lx + 1] = n + 1;
  int n0 = 1, n1 = 1;
  for (int i = 1; i <= lx; ++i) {
    while (n0 <= m0 && a0[n0] < x[i]) ++n0;
    if (a0[n0] == x[i]) a[i][0] = 1;
    while (n1 <= m1 && a1[n1] < x[i]) ++n1;
    if (a1[n1] == x[i]) a[i][1] = 1;
  }
  f[lx + 1][0] = f[lx + 1][1] = 0;
  for (int i = lx; i; --i) {
    for (int j = 0; j < 2; ++j) {
      f[i][j] = max(0ll, f[i + 1][j] - (x[i + 1] - x[i])), p[i][j] = i + 1;
      if (!a[i][j ^ 1]) {
        int v = f[i + 1][j ^ 1] - (x[i + 1] - x[i]);
        v = max(0, v);
        if (v < T && v < f[i][j]) f[i][j] = v, p[i][j] = -x[i];
      }
      if (!a[i + 1][j ^ 1] || x[i + 1] > x[i] + 1) {
        int v = f[i + 1][j ^ 1] - (x[i + 1] - x[i] - 1);
        v = max(0, v);
        if (v < T) {
          if (x[i + 1] == x[i] + 1) v += 1ll * a[i + 1][j] * T;
          --v;
          v = max(0, v);
          if (v < f[i][j]) f[i][j] = v, p[i][j] = -x[i] - 1;
        }
      }
      f[i][j] += 1ll * a[i][j] * T;
    }
  }
  if (f[1][0] && f[1][1])
    printf("No\n");
  else {
    printf("Yes\n");
    int now = f[1][1] == 0;
    if (now) tans[++tans[0]] = 0;
    for (int i = 1; i <= lx; ++i) {
      if (p[i][now] < 0) tans[++tans[0]] = -p[i][now], now ^= 1;
    }
    printf("%d\n", tans[0]);
    for (int i = 1; i <= tans[0]; ++i) printf("%d ", tans[i]);
    printf("\n");
    n0 = 1, n1 = 1, now = 0;
    tans[++tans[0]] = n + 1;
    for (int i = 1; i <= tans[0] + 1; ++i) {
      while (n0 <= m0 && a0[n0] <= tans[i]) {
        ++n0;
        if (now == 0) ++cnt[i];
      }
      while (n1 <= m1 && a1[n1] <= tans[i]) {
        ++n1;
        if (now == 1) ++cnt[i];
      }
      now ^= 1;
    }
    int num = 0, x = 0;
    now = 0;
    for (int i = 1; i <= tans[0]; ++i) {
      num = min(1ll * num, T);
      if (cnt[i]) {
        for (int j = 0; j < cnt[i]; ++j)
          tans2[++tans2[0]] = T - num + x + j * T, tans3[tans2[0]] = now + 1;
      }
      num += tans[i] - x, num -= cnt[i] * T;
      x = tans[i];
      now ^= 1;
    }
    printf("%d\n", tans2[0]);
    for (int i = 1; i <= tans2[0]; ++i) printf("%d %d\n", tans2[i], tans3[i]);
  }
  return 0;
}
