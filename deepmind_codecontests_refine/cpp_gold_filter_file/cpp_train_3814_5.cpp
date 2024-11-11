#include <bits/stdc++.h>
using namespace std;
const int fx[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, a[25], c[37][25];
int main() {
  scanf("%d", &n);
  int m = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 29) a[i]--, m++;
  }
  if (m > 1) {
    printf("No\n");
    return 0;
  }
  for (int i = 1; i <= 36; i++) {
    for (int j = 1; j <= n; j++) {
      int k = (i - 1) % 12 + 1;
      if (fx[k] == a[j])
        c[i][j] = c[i - 1][j - 1] + 1;
      else
        c[i][j] = 0;
      if (c[i][j] == n) {
        printf("Yes\n");
        return 0;
      }
    }
  }
  printf("No\n");
  return 0;
}
