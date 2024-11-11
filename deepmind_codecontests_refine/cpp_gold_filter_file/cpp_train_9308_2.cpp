#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Point {
  int x, y;
} A[2010], B[2010];
int cmp_A(Point a, Point b) { return a.x != b.x ? a.x < b.x : a.y < b.y; }
int cmp_B(Point a, Point b) { return a.y != b.y ? a.y < b.y : a.x < b.x; }
int f[2010][2010], qe[2010];
int ok(int L) {
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; ++i) {
    int y1 = A[i].y - L, y2 = A[i].y + L;
    for (int j = i + 1; j <= n; ++j) {
      if (A[j].x != A[i].x) break;
      if (A[j].y - A[i].y <= 2 * L)
        y2 = A[j].y + L, i = j;
      else
        break;
    }
    int cnt_qe = 0;
    for (int j = 1; j <= m; ++j)
      if (y1 <= B[j].y && B[j].y <= y2) {
        int x1 = B[j].x - L, x2 = B[j].x + L;
        for (int k = j + 1; k <= m; ++k) {
          if (B[k].y != B[j].y) break;
          if (B[k].x - B[j].x <= 2 * L)
            x2 = B[k].x + L, j = k;
          else
            break;
        }
        if (x1 <= A[i].x && A[i].x <= x2) qe[++cnt_qe] = j;
      }
    for (int j = 1; j <= cnt_qe; ++j)
      for (int k = j + 1; k <= cnt_qe; ++k) {
        ++f[qe[j]][qe[k]];
        if (f[qe[j]][qe[k]] == 2) return 1;
      }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &A[i].x, &A[i].y);
    A[i].x += A[i].y, A[i].y = A[i].x - 2 * A[i].y;
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &B[i].x, &B[i].y), B[i].x += B[i].y,
        B[i].y = B[i].x - 2 * B[i].y;
  }
  sort(A + 1, A + n + 1, cmp_A), sort(B + 1, B + m + 1, cmp_B);
  int l = 1, r = 2000010;
  while (l < r) {
    int mid = (l + r) / 2;
    if (ok(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (l == 2000010)
    printf("Poor Sereja!\n");
  else
    printf("%d\n", (l + 1) / 2);
  return 0;
}
