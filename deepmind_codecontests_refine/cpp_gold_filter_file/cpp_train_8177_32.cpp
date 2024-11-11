#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x;
}
bitset<4005> mat[2005];
int a[500005], b[500005], n, m;
int main() {
  int i, j;
  n = read();
  m = read();
  for (i = 1; i <= m; i++) {
    a[i] = read();
    b[i] = read();
    mat[a[i]][b[i]] = 1;
  }
  for (i = 1; i <= n; i++) {
    mat[i][i + n] = 1;
  }
  for (i = 1; i <= n; i++) {
    if (!mat[i][i]) {
      for (j = i + 1; j <= n; j++) {
        if (mat[j][i]) {
          swap(mat[j], mat[i]);
          break;
        }
      }
    }
    for (j = 1; j <= n; j++) {
      if (j == i) continue;
      if (mat[j][i]) {
        mat[j] ^= mat[i];
      }
    }
  }
  for (i = 1; i <= m; i++) {
    puts(mat[b[i]][a[i] + n] ? "NO" : "YES");
  }
  return 0;
}
