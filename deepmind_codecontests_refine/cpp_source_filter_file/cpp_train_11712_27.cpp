#include <bits/stdc++.h>
const int N = 100;
int n, m, f[N], g[N], c;
char x[N];
double z;
void solve(int *c, int n, int m) {
  int s = 0;
  for (int i = 1; i <= n; i++)
    if (c[i]) {
      s += c[i] - 1;
      z += s * (m - c[i]);
      if (!c[i + 1] || c[i + 1] < c[i]) s = 0;
    }
  for (int i = 1; i <= n; i++)
    if (c[i]) {
      z += s * (c[i] - 1);
      s += m - c[i];
      if (!c[i + 1] || c[i + 1] > c[i]) s = 0;
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", x + 1);
    for (int j = 1; j <= m; j++)
      if (x[j] == 'X') f[i] = j, g[j] = i, c++;
  }
  solve(f, n, m);
  solve(g, m, n);
  z *= 2;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) z += (m - !!f[i]) * (m - !!f[j]) * (i - j);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= i; j++) z += (n - !!g[i]) * (n - !!g[j]) * (i - j);
  z *= 2. / (n * m - c);
  z /= n * m - c;
  printf("%.9f\n", z);
}
