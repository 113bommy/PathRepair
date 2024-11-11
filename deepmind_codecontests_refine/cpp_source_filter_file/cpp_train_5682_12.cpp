#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, t = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') t = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
  return s * t;
}
const int N = 60;
int m;
long long n, S, T, R, Ans, h[N], f[N][N * 2][2];
bool Calc(long long A, long long B) {
  if (A < B || A <= 0 || B <= 0) return 0;
  return T = A / B, R = A % B, 1;
}
long long Solve(long long R, int a, int b, int n) {
  int lim = log2(R);
  memset(f[0], 0, sizeof(f[0])), f[0][0][0] = 1;
  for (int i = 1; i <= lim; i++) {
    int t = (R >> i & 1);
    memset(f[i], 0, sizeof(f[i]));
    for (int j = 0; j <= 2 * i - 2; j++)
      for (int k = 0; k <= 1; k++)
        if (f[i - 1][j][k])
          for (int x = 0; x <= 1; x++)
            if (!x || i < a)
              for (int y = 0; y <= 1; y++)
                if (!y || i < b)
                  if ((k + x + y) % 2 == t)
                    f[i][j + x + y][(k + x + y) / 2] += f[i - 1][j][k];
  }
  return f[lim][n][0];
}
int main() {
  S = read(), m = ceil(log2(S));
  for (int i = 0; i <= m; i++) h[i] = 1ll << i;
  for (int i = 1; i <= m; i++)
    if (Calc(S, h[i] - 1)) {
      for (int j = i - 1; j >= 0; j--)
        if (R >= h[j] - 1) R -= h[j] - 1;
      if (!R) Ans++;
    }
  for (int i = 1; i < m; i++)
    for (int j = 1; j < m; j++)
      if (Calc(S - h[j] + 1, h[i + 1] + h[j + 1] - 3)) {
        if (!R) {
          Ans++;
          continue;
        }
        for (int k = 1; k <= i + j; k++)
          if (!(R + k & 1)) Ans += Solve(R + k, i, j, k);
      }
  printf("%lld", Ans);
  return 0;
}
