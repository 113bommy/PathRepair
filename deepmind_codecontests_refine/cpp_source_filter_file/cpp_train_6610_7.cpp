#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
struct P {
  int u, v, d;
} e[155];
bool cmp(P a, P b) { return a.d < b.d; }
bitset<155> now[155], a[155], C[155], line[155], row[155], tmp[155];
int dis[155][155];
void mul(bitset<155> A[155], bitset<155> B[155], bitset<155> D[155]) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      line[i][j] = A[i][j];
      row[j][i] = B[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) D[i][j] = (line[i] & row[j]).any();
  }
}
void quick_mul(bitset<155> A[155], int p, bitset<155> B[155]) {
  for (int i = 1; i <= n; i++) B[i].reset();
  for (int i = 1; i <= n; i++) B[i][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) C[i][j] = A[i][j];
  while (p) {
    if (p & 1) mul(B, C, B);
    mul(C, C, C);
    p >>= 1;
  }
}
int ans = 1000000007;
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= m; i++)
    e[i].u = read(), e[i].v = read(), e[i].d = read();
  sort(e + 1, e + m + 1, cmp);
  for (int i = 1; i <= n; i++) a[i][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) dis[i][j] = 1000000007;
  if (e[1].d) {
    puts("Impossible");
    return 0;
  }
  int tim;
  for (int i = 1; i <= m; i++) {
    tim = e[i].d;
    now[e[i].u][e[i].v] = 1;
    for (int x = 1; x <= n; x++)
      for (int y = 1; y <= n; y++)
        if (dis[x][e[i].u] < 1000000007 && dis[e[i].v][y] < 1000000007)
          dis[x][y] = min(dis[x][y], dis[x][e[i].u] + 1 + dis[e[i].v][y]);
    for (int j = 1; j <= n; j++)
      if (a[1][j] && dis[j][n] != 1000000007) ans = min(ans, dis[j][n] + tim);
    if (i < m) {
      quick_mul(now, e[i + 1].d - tim, tmp);
      mul(a, tmp, a);
    }
  }
  if (ans == 1000000007)
    puts("Impossble");
  else
    cout << ans << endl;
  return 0;
}
