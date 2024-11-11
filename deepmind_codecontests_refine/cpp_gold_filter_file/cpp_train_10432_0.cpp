#include <bits/stdc++.h>
using namespace std;
char s[2048][2048], row[2048], col[2048], row2[2048], col2[2048];
int main() {
  int i, j, k, n, an = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (j = 0; j < n; j++) s[i][j] -= '0';
  }
  for (i = n - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (s[i][j] ^ row[i] ^ col[j]) {
        row[i] ^= 1;
        col[j] ^= 1;
        an++;
      }
    }
  }
  for (i = 0; i < n - 1; i++)
    for (j = n - 1; j > i; j--) {
      if (s[i][j] ^ row2[i] ^ col2[j]) {
        row2[i] ^= 1;
        col2[j] ^= 1;
        an++;
      }
    }
  for (i = 0; i < n; i++)
    if (row[i] ^ row2[i] ^ col[i] ^ col2[i] ^ s[i][i]) an++;
  printf("%d\n", an);
  return 0;
}
