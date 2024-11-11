#include <bits/stdc++.h>
using namespace std;
int a[110][110], fuck[110];
int main() {
  int n, m, k, now, tempa, tempb, i, j, x, temp;
  scanf("%d%d%d", &n, &m, &k);
  int ans = n * m;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &a[i][j]);
  if (n > k) {
    for (i = 0; i < n; i++) {
      now = 0;
      for (j = i - 1; j >= 0; j--) {
        tempa = 0;
        tempb = 0;
        for (x = 0; x < m; x++) {
          if (a[j][x] == a[i][x])
            tempb++;
          else
            tempa++;
        }
        now = now + min(tempa, tempb);
      }
      for (j = i + 1; j < n; j++) {
        tempa = 0;
        tempb = 0;
        for (x = 0; x < m; x++) {
          if (a[j][x] == a[i][x])
            tempb++;
          else
            tempa++;
        }
        now = now + min(tempa, tempb);
      }
      if (now < ans) ans = now;
    }
    if (ans > k)
      printf("-1\n");
    else
      printf("%d\n", ans);
  } else {
    for (temp = 0; temp < (1 << n); temp++) {
      for (i = 0; i < n; i++) {
        if (temp & (1 << i))
          fuck[i] = 1;
        else
          fuck[i] = 0;
      }
      now = 0;
      for (j = 0; j < m; j++) {
        tempa = 0;
        tempb = 0;
        for (x = 0; x < n; x++) {
          if (a[x][j] == fuck[x])
            tempb++;
          else
            tempa++;
        }
        now = now + min(tempa, tempb);
      }
      if (now < ans) ans = now;
    }
    if (ans > k)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
