#include <bits/stdc++.h>
using namespace std;
int main() {
  int row[5005][2] = {0}, col[5005][2] = {0}, i, j, r, c, k, ch, n, paint;
  scanf("%d %d %d", &r, &c, &k);
  for (i = 1; i <= k; i++) {
    scanf("%d %d %d", &ch, &n, &paint);
    if (ch == 1) {
      row[n][1] = paint;
      row[n][0] = i;
    } else {
      col[n][1] = paint;
      col[n][0] = i;
    }
  }
  for (i = 1; i <= r; i++) {
    for (j = 1; j <= c; j++) {
      if (row[i][0] > col[j][0])
        printf("%d ", row[i][1]);
      else
        printf("%d ", col[j][1]);
    }
    printf("\n");
  }
  return 0;
}
