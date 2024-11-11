#include <bits/stdc++.h>
using namespace std;
int n, m, q, a[1100][1100], b[1100][1100], op, x, y, L[1100][1100],
    R[1100][1100], L1[1100][1100], R1[1100][1100], mm1[1100], mm2[1100];
void recalc(int n, int m, int a[1100][1100], int x, int L[1100][1100],
            int R[1100][1100]) {
  int pre = m + 1;
  for (int i = m; i; i--) {
    if (!a[x][i]) pre = i;
    R[x][i] = pre;
  }
  pre = 0;
  for (int i = 1; i <= m; i++) {
    if (!a[x][i]) pre = i;
    L[x][i] = pre;
  }
}
int query(int n, int m, int x, int y, int L[1100][1100], int R[1100][1100]) {
  int ans = 0;
  mm1[x] = mm2[x] = R[x][y];
  for (int i = x + 1; i <= n; i++) mm2[i] = min(mm2[i - 1], R[i][y]);
  for (int i = x - 1; i; i--) mm1[i] = min(mm1[i + 1], R[i][y]);
  int q = 1, h = n;
  for (int i = y; i <= R[x][y]; i++) {
    while (mm1[q] < i) q++;
    while (mm2[h] < i) h--;
    ans = max(ans, (h - q + 1) * (i - y));
  }
  mm1[x] = mm2[x] = L[x][y];
  for (int i = x + 1; i <= n; i++) mm2[i] = max(mm2[i - 1], L[i][y]);
  for (int i = x - 1; i; i--) mm1[i] = max(mm1[i + 1], L[i][y]);
  q = 1, h = n;
  for (int i = y; i >= L[x][y]; i--) {
    while (mm1[q] > i) q++;
    while (mm2[h] > i) h--;
    ans = max(ans, (h - q + 1) * (y - i));
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]), b[j][i] = a[i][j];
  for (int i = 1; i <= n; i++) recalc(n, m, a, i, L, R);
  for (int i = 1; i <= m; i++) recalc(m, n, b, i, L1, R1);
  while (q--) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      a[x][y] = 1 - a[x][y], b[y][x] = 1 - b[y][x], recalc(n, m, a, x, L, R),
      recalc(m, n, b, y, L1, R1);
    else
      printf("%d\n", max(query(n, m, x, y, L, R), query(m, n, y, x, L1, R1)));
  }
}
