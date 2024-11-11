#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stck:1024000000,1024000000")
char a[15][15], b[15][15], c[15][15];
int n;
bool solve() {
  int x1 = 1, x2 = 1, x3 = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] != b[i][j]) x1 = 0;
      if (a[i][j] != b[n - i + 1][j]) x2 = 0;
      if (a[i][j] != b[i][n - j + 1]) x3 = 0;
    }
  }
  if (x1 || x2 || x3) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  for (int i = 1; i <= n; i++) scanf("%s", b[i] + 1);
  int ok = 0;
  for (int k = 1; k <= 4; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        c[n - j + 1][i] = a[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = c[i][j];
      }
    }
    if (solve()) ok = 1;
  }
  puts(ok ? "Yes" : "No");
  return 0;
}
