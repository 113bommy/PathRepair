#include <bits/stdc++.h>
using namespace std;
char matrix[110][110];
int main() {
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= 100; j++) matrix[i][j] = '*';
  int n;
  scanf("%d", &n);
  int ds = 1;
  int m = n / 2, b, e;
  b = e = m + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = b; j <= e; j++) {
      matrix[i][j] = 'D';
    }
    if (i >= n / 2 + 1) {
      b++;
      e--;
    } else {
      b--;
      e++;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) printf("%c", matrix[i][j]);
    printf("\n");
  }
  return 0;
}
