#include <bits/stdc++.h>
using namespace std;
const int next_x[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int next_y[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int inf = 2147483647;
const long long linf = 1e15;
const double PI = acos(-1.0);
long long read() {
  long long t = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    t = t * 10 + ch - '0';
    ch = getchar();
  }
  return t * f;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
extern const int MAXN = 55;
extern const int N = 2000000;
int n;
char s[MAXN][MAXN];
int f[MAXN][MAXN][MAXN][MAXN];
int solve(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return s[x1][y1] == '#';
  if (f[x1][y1][x2][y2] != -1) return f[x1][y1][x2][y2];
  f[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
  for (int i = x1; i <= x2 - 1; i++)
    f[x1][y1][x2][y2] =
        min(f[x1][y1][x2][y2], solve(x1, y1, i, y2) + solve(i + 1, y1, x2, y2));
  for (int i = y1; i <= y2 - 1; i++)
    f[x1][y1][x2][y2] =
        min(f[x1][y1][x2][y2], solve(x1, y1, x2, i) + solve(x1, i + 1, x2, y2));
  return f[x1][y1][x2][y2];
}
int work() {
  memset(f, -1, sizeof(f));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  return printf("%d\n", solve(1, 1, n, n));
}
int main() {
  work();
  return 0;
}
