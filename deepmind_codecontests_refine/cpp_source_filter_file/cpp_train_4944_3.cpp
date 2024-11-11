#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z, k, w, X, Y;
int A[15][2], B[15][2], ans;
int main() {
  scanf("%d", &n);
  scanf("%d", &x);
  for (int i = (0); i < (x); i++) {
    scanf("%d", &A[i][0]);
    A[i][1] = i;
  }
  X = x;
  scanf("%d", &y);
  for (int i = (0); i < (y); i++) {
    scanf("%d", &B[i][0]);
    B[i][1] = i + x;
  }
  Y = y;
  k = w = 0;
  while (1) {
    ans++;
    if (A[k][0] > B[w][0]) {
      if (x >= 10) x = 0;
      A[x][0] = B[w][0];
      A[x][1] = B[w][1];
      x++;
      if (x >= 10) x = 0;
      A[x][0] = A[k][0];
      A[x][1] = A[k][1];
      x++;
      X++;
      Y--;
    } else {
      if (y >= 10) y = 0;
      B[y][0] = A[k][0];
      B[y][1] = A[k][1];
      y++;
      if (y >= 10) x = 0;
      B[y][0] = B[w][0];
      B[y][1] = B[w][1];
      y++;
      Y++;
      X--;
    }
    if (X == 0 || Y == 0) break;
    k++;
    w++;
    if (k == 10) k = 0;
    if (w == 10) w = 0;
    if (ans > 5000000) break;
  }
  if (X == 0)
    printf("%d 2\n", ans);
  else if (Y == 0)
    printf("%d 1\n", ans);
  else
    printf("-1\n");
  return 0;
}
