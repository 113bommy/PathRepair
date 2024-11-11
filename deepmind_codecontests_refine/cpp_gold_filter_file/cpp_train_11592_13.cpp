#include <bits/stdc++.h>
using namespace std;
int a[10];
int b[10];
int c[10];
bool judge(int c[], int n) {
  int d[5][5] = {0};
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = c[(i - 1) * n + j];
  int val = 0;
  for (int i = 1; i <= n; i++) val += d[1][i];
  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 1; j <= n; j++) s += d[i][j];
    if (s != val) return false;
  }
  for (int i = 1; i <= n; i++) {
    int s = 0;
    for (int j = 1; j <= n; j++) s += d[j][i];
    if (s != val) return false;
  }
  int s = 0;
  for (int i = 1; i <= n; i++) s += d[i][i];
  if (s != val) return false;
  s = 0;
  for (int i = 1; i <= n; i++) s += d[i][n - i + 1];
  if (s != val) return false;
  return true;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n * n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n * n; i++) b[i] = i;
    do {
      for (int i = 1; i <= n * n; i++) {
        c[i] = a[b[i]];
      }
      if (judge(c, n)) {
        int val = 0;
        for (int i = 1; i <= n; i++) val += c[i];
        printf("%d\n", val);
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) printf("%d ", c[(i - 1) * n + j]);
          printf("\n");
        }
        break;
      }
    } while (next_permutation(b + 1, b + 1 + n * n));
  }
  return 0;
}
