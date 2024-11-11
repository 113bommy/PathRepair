#include <bits/stdc++.h>
inline int read() {
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  int k = 0, kk = 1;
  if (c == '-') c = getchar(), kk = -1;
  while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar();
  return kk * k;
}
using namespace std;
void write(int x) {
  if (x < 0) x = -x, putchar('-');
  if (x / 10) write(x / 10);
  putchar(x % 10 + '0');
}
void writeln(int x) {
  write(x);
  puts("");
}
int n, k, a[200][200], dd, f[200], ans, z[200];
signed main() {
  n = read();
  k = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = read();
  for (int i = 1; i <= n; i++) a[i][i] = 0;
  srand(23333);
  ans = 1;
  for (int l = 1; l <= 100000; l++) {
    z[1] = rand() % n + 1;
    dd = 0;
    for (int i = 1; i <= n; i++) f[i] = a[z[1]][i], dd += f[i];
    for (int i = 2; i <= n && dd; i++) {
      int ddd = rand() % dd + 1;
      for (int j = 1; j <= n; j++) {
        if (f[j]) ddd--;
        if (ddd == 0) {
          z[i] = j;
          break;
        }
      }
      ans = max(ans, i);
      dd = 0;
      for (int j = 1; j <= n; j++) f[j] &= a[z[i]][j], dd += f[j];
    }
  }
  printf("%.10f", (1.0 * k / ans) * (1.0 * k / ans) * (ans * (ans - 1) / 2));
}
