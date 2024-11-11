#include <bits/stdc++.h>
using namespace std;
template <typename T>
double DIS(T va, T vb) {
  return sqrt((double)(va.x - vb.x) * (va.x - vb.x) +
              (va.y - vb.y) * (va.y - vb.y));
}
template <class T>
inline T INT_LEN(T v) {
  int len = 1;
  while (v /= 10) ++len;
  return len;
}
template <typename T>
inline T square(T va, T vb) {
  return va * va + vb * vb;
}
int x[-~24], y[-~24], dp[1 << 24], rec[1 << 24], dis[24][24];
int N;
void input(int n) {
  int i;
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x[i], &y[i]);
  }
}
void make_map(int n) {
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      dis[i][j] = square(x[i] - x[j], y[i] - y[j]);
    }
  }
}
void print(int n) {
  int m = (1 << n) - 1;
  printf("%d\n", dp[m]);
  int i;
  while (m) {
    printf("0 ");
    for (i = 0; i < n; i++) {
      if ((m ^ rec[m]) & (1 << i)) {
        printf("%d ", -~i);
      }
    }
    m = rec[m];
  }
  puts("0");
}
void print2(int n) {
  int i, j;
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= n; j++) {
      if (j) putchar(' ');
      printf("%d", dis[i][j]);
    }
    puts("");
  }
  puts("");
}
void solve(int n) {
  make_map(n);
  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;
  int m = 1 << n;
  int i, j, k;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      if ((i & (1 << j)) == 0) {
        if (dp[i ^ (1 << j)] > dp[i] + dis[j][n] + dis[j][n]) {
          dp[i ^ (1 << j)] = dp[i] + dis[j][n] + dis[j][n];
          rec[i ^ (1 << j)] = i;
        }
        int mask = i ^ (1 << j);
        for (k = -~j; k < n; k++) {
          if (i & (1 << k)) continue;
          if (dp[mask ^ (1 << k)] > dp[i] + dis[n][j] + dis[j][k] + dis[k][n]) {
            dp[mask ^ (1 << k)] = dp[i] + dis[n][j] + dis[j][k] + dis[k][n];
            rec[mask ^ (1 << k)] = i;
          }
        }
        break;
      }
    }
  }
  print(n);
}
int main(void) {
  int X, Y;
  while (2 == scanf("%d%d", &X, &Y)) {
    scanf("%d", &N);
    x[N] = X, y[N] = Y;
    input(N);
    solve(N);
  }
  return 0;
}
