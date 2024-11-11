#include <bits/stdc++.h>
using namespace std;
int ROW[] = {+1, -1, +0, +0};
int COL[] = {+0, +0, +1, -1};
int X[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int Y[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int KX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int KY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int GCD(int a, int b) { return b == 0 ? a : GCD(b, a % b); }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
bool CMP(int a, int b) { return a > b; }
template <class T>
inline bool fastread(T &x) {
  int c = getchar();
  int sgn = 1;
  while (~c && c < '0' || c > '9') {
    if (c == '-') sgn = -1;
    c = getchar();
  }
  for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar()) x = x * 10 + c - '0';
  x *= sgn;
  return ~c;
}
clock_t Start = clock();
void Time() {}
int main() {
  int n, m, a[100][100], b[100][100], x[100][100], y[100][100];
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> b[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      x[i][j] = min(a[i][j], b[i][j]);
      y[i][j] = max(a[i][j], b[i][j]);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (x[i][j] <= x[i - 1][j] or y[i][j] <= y[i - 1][j]) {
        printf("Impossible\n");
        return 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (x[i][j] <= x[i][j - 1] or y[i][j] <= y[i][j - 1]) {
        printf("Impossible\n");
        return 0;
      }
    }
  }
  printf("Possible\n");
  return 0;
}
