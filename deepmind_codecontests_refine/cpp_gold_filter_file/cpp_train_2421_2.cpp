#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
int l[N], r[N], u[N], d[N];
int f[N][2];
int calc(int n, int m, int *l, int *r, int *u, int *d) {
  memset(f, 0, sizeof(f));
  for (int i = (1), _x = (m); i <= _x; i++) f[1][u[i] ^ 1]++;
  f[1][l[1] ^ 1]++, f[1][r[1] ^ 1]++;
  for (int i = (2), _x = (n); i <= _x; i++) {
    for (int j = (0), _x = (1); j <= _x; j++) {
      int s = (l[i] != j) + (r[i] != j);
      f[i][j] = min(f[i - 1][j], f[i - 1][j ^ 1] + m) + s;
    }
  }
  for (int i = (1), _x = (m); i <= _x; i++) f[n][d[i] ^ 1]++;
  return min(f[n][0], f[n][1]);
}
int ok(char first) { return first == 'R' || first == 'B'; }
void red(int n, int *ch) {
  for (int i = (1), _x = (n); i <= _x; i++) {
    char first;
    while (!ok(first = getchar()))
      ;
    ch[i] = first == 'B';
  }
  return;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  red(n, l), red(n, r), red(m, u), red(m, d);
  int ans = min(calc(n, m, l, r, u, d), calc(m, n, u, d, l, r));
  printf("%d\n", ans);
  return 0;
}
