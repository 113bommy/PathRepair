#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2147483647;
inline int read();
const int N = 5e5 + 2;
const int H = 34;
int n, c;
double pre, now;
int f[N];
double dp[N][H + 2];
void Insert(int x) {
  f[++c] = x;
  for (int i = 0; i <= H; ++i) dp[c][i] = 1;
  if (x) pre = dp[x][0], dp[x][0] *= 0.5;
  for (int i = 1, y = x; i <= H; ++i) {
    int p = f[y];
    if (!p) break;
    now = dp[p][i];
    dp[p][i] = dp[p][i] / (0.5 + 0.5 * pre) * (0.5 + 0.5 * dp[y][i - 1]);
    pre = now;
    y = f[y];
  }
}
void Query(int x) {
  double ans = 0;
  for (int i = 1; i <= H; ++i) ans += (dp[x][i] - dp[x][i - 1]) * i;
  printf("%.10lf\n", ans);
}
void Work() {
  n = read();
  Insert(0);
  for (int i = 1; i <= n; ++i)
    if (read() == 1)
      Insert(read());
    else
      Query(read());
}
int main() {
  Work();
  return 0;
}
inline int read() {
  char c;
  bool type = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') type = 0;
  int ans = c ^ 48;
  while ((c = getchar()) >= '0' && c <= '9')
    ans = (ans << 3) + (ans << 1) + (c ^ 48);
  return type ? ans : -ans;
}
