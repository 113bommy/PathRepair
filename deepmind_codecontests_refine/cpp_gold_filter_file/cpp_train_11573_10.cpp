#include <bits/stdc++.h>
using namespace std;
int ans = 1, md = 1000003, n, m;
char a[900000];
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) scanf("%c", &a[(i - 1) * m + j]);
    scanf("\n");
  }
  for (int i = 1; i <= n; i++) {
    int c = 3;
    for (int j = 1; j <= m; j++) {
      if ((((a[(i - 1) * m + j] == '1') || (a[(i - 1) * m + j] == '2')) &&
           (j % 2 == 0)) ||
          (((a[(i - 1) * m + j] == '3') || (a[(i - 1) * m + j] == '4')) &&
           (j % 2 == 1))) {
        c = c & 1;
      }
      if ((((a[(i - 1) * m + j] == '1') || (a[(i - 1) * m + j] == '2')) &&
           (j % 2 == 1)) ||
          (((a[(i - 1) * m + j] == '3') || (a[(i - 1) * m + j] == '4')) &&
           (j % 2 == 0))) {
        c = c & 2;
      }
    }
    if (c == 0) ans = 0;
    if (c == 3) ans = (ans * 2) % md;
  }
  for (int j = 1; j <= m; j++) {
    int c = 3;
    for (int i = 1; i <= n; i++) {
      if ((((a[(i - 1) * m + j] == '1') || (a[(i - 1) * m + j] == '4')) &&
           (i % 2 == 0)) ||
          (((a[(i - 1) * m + j] == '2') || (a[(i - 1) * m + j] == '3')) &&
           (i % 2 == 1))) {
        c = c & 1;
      }
      if ((((a[(i - 1) * m + j] == '1') || (a[(i - 1) * m + j] == '4')) &&
           (i % 2 == 1)) ||
          (((a[(i - 1) * m + j] == '2') || (a[(i - 1) * m + j] == '3')) &&
           (i % 2 == 0))) {
        c = c & 2;
      }
    }
    if (c == 0) ans = 0;
    if (c == 3) ans = (ans * 2) % md;
  }
  printf("%d\n", ans);
}
