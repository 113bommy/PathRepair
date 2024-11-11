#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e3 + 100;
int n, m, c1, c2;
double f[maxN + 1][maxN + 1];
bool row[maxN + 1], line[maxN + 1];
inline int read() {
  int num = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) num = (num << 3) + (num << 1) + (ch ^ 48), ch = getchar();
  return num * f;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    row[read()] = true;
    line[read()] = true;
  }
  for (int i = 1; i <= n; i++) c1 += row[i], c2 += line[i];
  for (int i = n; i >= 1; i--)
    for (int j = n; j >= 1; j--) {
      if (i == n && j == n) continue;
      f[i][j] = f[i + 1][j] * (n - i) * j + f[i][j + 1] * i * (n - j) +
                f[i + 1][j + 1] * (n - i) * (n - j) + n * n;
      f[i][j] /= (double)(n * n - i * j);
    }
  printf("%.10lf", f[c1][c2]);
  return 0;
}
