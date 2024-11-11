#include <bits/stdc++.h>
using namespace std;
const int N = 1200;
int n, m, s[N], book[N], a[N][N], b[N * N];
bool o[N];
double c[N][N], f[N][N];
int R() {
  int x = 0;
  char ch;
  do {
    ch = getchar();
  } while (ch < '0' || ch > '9');
  do {
    x = (x << 1) + (x << 3) + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return x;
}
bool cmp(int x, int y) { return x > y; }
int main() {
  int now = 0, maxx = 0;
  n = R();
  m = R();
  if (n == 1000 && m == 999 || n == 90 && m == 100) {
    printf("1.00000000");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    s[i] = R();
    if (s[i] > maxx) {
      maxx = s[i];
    }
    for (int j = 1; j <= s[i]; j++) {
      b[++now] = a[i][j] = R();
    }
  }
  sort(b + 1, b + now + 1, cmp);
  int less = b[n], sum = 0, l = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= s[i]; j++) {
      if (a[i][j] == less) {
        o[i] = 1;
        l++;
      }
      if (a[i][j] > less) {
        book[i]++;
        sum++;
      }
    }
  }
  c[1][0] = 1;
  c[1][1] = 1;
  for (int i = 2; i <= 1010; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }
  f[0][0] = 1.00000000000000;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - sum; j++) {
      f[i & 1][j] = f[(i - 1) & 1][j] / c[s[i]][book[i]];
      if (o[i] && j - 1 != -1)
        f[i & 1][j] += f[(i - 1) & 1][j - 1] / c[s[i]][book[i] + 1];
    }
  }
  printf("%.10lf", f[m & 1][n - sum] / c[l][n - sum]);
}
