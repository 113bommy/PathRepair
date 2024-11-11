#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
} ans[1000];
char save[60][60], a[60][60];
int fa1[50], fa2[50], fsum1, fsum2, n, m, asum;
void print() {
  int i, j;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) printf("%c", save[i][j]);
    printf("\n");
  }
}
bool rotatecheck(int x, int y, int height, int width, int rot) {
  int i, j, ii, jj;
  if (rot == 0) {
    for (i = 1; i <= height; i++)
      for (j = 1; j <= width; j++) {
        save[i][j] = a[x + i - 1][y + j - 1];
      }
  } else if (rot == 1) {
    if (width != height) return false;
    for (i = 1; i <= height; i++)
      for (j = 1; j <= width; j++) {
        save[j][height - i + 1] = a[x + i - 1][y + j - 1];
      }
  } else if (rot == 2) {
    for (i = 1; i <= height; i++)
      for (j = 1; j <= width; j++) {
        save[height - i + 1][width - j + 1] = a[x + i - 1][y + j - 1];
      }
  } else if (rot == 3) {
    if (width != height) return false;
    for (i = 1; i <= height; i++)
      for (j = 1; j <= width; j++) {
        save[width - j + 1][i] = a[x + i - 1][y + j - 1];
      }
  }
  int gx = n / height, gy = m / width;
  for (i = 0; i < gx; i++)
    for (j = 0; j < gy; j++) {
      int xx = i * height + 1, yy = j * width + 1;
      if (xx != x || yy != y) {
        bool bo = true;
        for (ii = 1; ii <= height; ii++)
          for (jj = 1; jj <= width; jj++)
            if (save[ii][jj] != a[xx + ii - 1][yy + jj - 1]) {
              bo = false;
              break;
            }
        if (bo) return true;
      }
    }
  return false;
}
bool cmp(node x1, node x2) {
  if ((x1.x * x1.y) < (x2.x * x2.y)) return true;
  if ((x1.x * x1.y) == (x2.x * x2.y) && (x1.x < x2.x)) return true;
  return false;
}
int main() {
  int i, j, ii, jj, rot, asum = 0;
  scanf("%d%d", &n, &m);
  getchar();
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      scanf("%c", &a[i][j]);
    }
    getchar();
  }
  for (i = 1; i <= n; i++)
    if (n % i == 0) fa1[++fsum1] = i;
  for (i = 1; i <= m; i++)
    if (m % i == 0) fa2[++fsum2] = i;
  for (i = 1; i <= fsum1; i++)
    for (j = 1; j <= fsum2; j++) {
      int x = fa1[i], y = fa2[j];
      int gx = n / x, gy = m / y;
      bool bk = true;
      for (ii = 0; ii < gx; ii++) {
        for (jj = 0; jj < gy; jj++) {
          int xx = ii * x + 1, yy = jj * y + 1;
          bk = true;
          for (rot = 0; rot <= 3; rot++) {
            if (rotatecheck(xx, yy, x, y, rot)) {
              bk = false;
              break;
            }
          }
          if (!bk) break;
        }
        if (!bk) break;
      }
      if (bk) {
        ans[++asum].x = x;
        ans[asum].y = y;
      }
    }
  printf("%d\n", asum);
  sort(&ans[1], &ans[asum + 1], cmp);
  printf("%d %d\n", ans[1].x, ans[1].y);
  return 0;
}
