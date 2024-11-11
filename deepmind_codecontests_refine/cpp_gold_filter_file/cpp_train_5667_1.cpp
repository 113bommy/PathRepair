#include <bits/stdc++.h>
using namespace std;
const int Max = 2100;
double dp[Max][Max];
int n, m;
double solve(int x, int y) {
  double t, a, b, N = n, temp;
  if (dp[x][y] > -1) return dp[x][y];
  if (x == 0 && y == 0) return dp[x][y] = 0;
  a = x;
  b = y;
  temp = t = N * N / ((a + b) * N - a * b);
  if (x != 0) t += solve(a - 1, b) * ((N - b) * a / ((a + b) * N - a * b));
  if (y != 0) t += solve(a, b - 1) * ((N - a) * b / ((a + b) * N - a * b));
  if (x != 0 && y != 0)
    t += solve(a - 1, b - 1) * ((a * b) / ((a + b) * N - a * b));
  return dp[x][y] = t;
}
int x[Max] = {0};
int y[Max] = {0};
int main() {
  cin >> n >> m;
  memset(dp, -0x4, sizeof(dp));
  int lx = n, ly = n;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (x[a] == 0) {
      lx--;
      x[a] = 1;
    }
    if (y[b] == 0) {
      ly--;
      y[b] = 1;
    }
  }
  printf("%.10lf", solve(lx, ly));
  return 0;
}
