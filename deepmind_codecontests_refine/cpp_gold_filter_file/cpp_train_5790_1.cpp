#include <bits/stdc++.h>
using namespace std;
__inline int read() {
  char c = getchar();
  int x = 0, f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
__inline string next_line() {
  const int SIZE = 1100000;
  static char buf[SIZE + 1];
  static int p = SIZE;
  string res;
  int f = 1;
  while ((p < SIZE || (p = 0, buf[fread(buf, 1, SIZE, stdin)] = 0, buf[0])) &&
         (buf[p] != '\n' && (res += buf[p], f = 0, 1) || f))
    ++p;
  return res;
}
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int MAXN = 2505;
const int MOD = 1e9 + 7;
int sgn(double x) {
  if (fabs(x) < eps) return 0;
  if (x < 0)
    return -1;
  else
    return 1;
}
int n, m;
char a[MAXN][MAXN];
int sum[MAXN][MAXN];
int get(int k) {
  int ret = 0;
  for (int i = 1; i <= n; i += k) {
    for (int j = 1; j <= m; j += k) {
      int x = min(i + k - 1, n), y = min(j + k - 1, m);
      int tmp = sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];
      ret += min(tmp, k * k - tmp);
    }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  memset(sum, 0, sizeof(sum));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum[i][j] =
          sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (a[i][j] == '1');
    }
  }
  int ans = INF;
  for (int k = 2; k <= max(n, m); k++) {
    ans = min(ans, get(k));
  }
  printf("%d\n", ans);
}
