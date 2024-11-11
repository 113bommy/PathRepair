#include <bits/stdc++.h>
const int RXD = 1e9 + 7;
const int N = 2e5 + 10;
using namespace std;
struct data {
  int x, y, next;
} e[N << 1];
int head[N], dp[N][2], n, x, cnt, tmp;
int read() {
  int x = 0, f = 1, c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
void Insert(int x, int y) {
  e[++cnt].x = x;
  e[cnt].y = y;
  e[cnt].next = head[x];
  head[x] = cnt;
}
void Solve() {
  for (int x = n; x; x--) {
    dp[x][0] = 0;
    dp[x][1] = 1;
    if (!head[x]) continue;
    for (int i = head[x]; i; i = e[i].next) {
      int y = e[i].y;
      int a =
          (1ll * dp[x][0] * dp[y][0] % RXD + 1ll * dp[x][1] * dp[y][1] % RXD) %
          RXD;
      int b =
          (1ll * dp[x][1] * dp[y][0] % RXD + 1ll * dp[x][0] * dp[y][1] % RXD) %
          RXD;
      dp[x][0] = (dp[x][0] + a) % RXD;
      dp[x][1] = (dp[x][1] + b) % RXD;
    }
    dp[x][0] = 2ll * dp[x][0] % RXD;
    dp[x][1] = 2ll * dp[x][1] % RXD;
    int p[3] = {1, 1, 0};
    for (int i = head[x]; i; i = e[i].next) {
      int y = e[i].y;
      p[0] = ((1ll * p[0] * dp[y][0]) % RXD + p[0]) % RXD;
      tmp = p[2];
      p[2] = ((1ll * p[1] * dp[y][1]) % RXD + p[2]) % RXD;
      p[1] = ((1ll * tmp * dp[y][1]) % RXD + p[1]) % RXD;
    }
    dp[x][0] = (1ll * dp[x][0] - p[0] + RXD) % RXD;
    dp[x][1] = (1ll * dp[x][1] - p[2] + RXD) % RXD;
  }
}
int main() {
  n = read();
  for (int i = 2; i <= n; i++) {
    x = read();
    Insert(x, i);
  }
  Solve();
  printf("%d\n", (dp[1][0] + dp[1][1]) % RXD);
}
