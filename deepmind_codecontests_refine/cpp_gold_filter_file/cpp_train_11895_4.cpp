#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
int f[110][110], L[110][110], R[110][110];
int n, m;
int main() {
  n = read(), m = read();
  for (register long long i = 1; i <= n; i++) {
    int T = read();
    while (T--) {
      int l = read(), r = read();
      for (register long long j = l; j <= r; j++) L[i][j] = l, R[i][j] = r;
    }
  }
  for (register long long r = 1; r <= m; r++)
    for (register long long l = r; l >= 1; l--)
      for (register long long x = l; x <= r; x++) {
        int c = 0;
        for (register long long i = 1; i <= n; i++)
          if (L[i][x] >= l && R[i][x] <= r) c++;
        f[l][r] = max(f[l][r], f[l][x - 1] + f[x + 1][r] + c * c);
      }
  printf("%d\n", f[1][m]);
  return 0;
}
