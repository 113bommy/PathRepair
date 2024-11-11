#include <bits/stdc++.h>
using namespace std;
const int maxn = 400001, maxh = 21, maxl = 1 << maxh;
int n, len, ans;
int A[maxn], s[maxn], f[maxn];
int g[maxh][maxl];
char st[maxh];
int calc(int x, int y) {
  int i, j, nx, ny;
  for (i = j = nx = ny = 0; i < len; ++i) {
    nx = nx + (x & (1 << i));
    ny = ny * 2 + ((y >> (len - i - 1)) & 1);
    if (nx == ny) j = max(j, i + 1);
  }
  return len - j;
}
int main() {
  int i, j, least, sum, x, nx, ny;
  scanf("%d\n", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%s", st);
    len = strlen(st);
    for (j = 0; j < len; ++j) A[i] = A[i] * 2 + st[j] - '0';
  }
  s[1] = len;
  for (i = 2; i <= n; ++i) s[i] = s[i - 1] + calc(A[i - 1], A[i]);
  memset(g, 10, sizeof(g));
  least = f[0] = len;
  for (i = 1; i < n; ++i) {
    sum = least;
    x = A[i + 1];
    for (j = nx = 0; j < len; ++j) {
      nx = nx * 2 + ((x >> (len - j - 1)) & 1);
      sum = min(sum, g[j][nx] + len - j - 1);
    }
    f[i] = sum + s[i];
    x = A[i];
    for (j = ny = 0; j < len; ++j) {
      ny = ny + (x & (1 << j));
      g[j][ny] = min(g[j][ny], f[i] - s[i + 1]);
    }
    if (f[i] - s[i + 1] + len < least) least = f[i] - s[i + 1] + len;
  }
  ans = s[n];
  for (i = 0; i < n; ++i) ans = min(ans, f[i] + s[n] - s[i + 1]);
  printf("%d", ans);
  return 0;
}
