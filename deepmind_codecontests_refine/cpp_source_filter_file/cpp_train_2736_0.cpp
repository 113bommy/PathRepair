#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int tot;
int op[1005 * 1005 * 3][7];
string s;
int a[1005][1005];
int p[1005][1005];
int sum;
void check(int x1, int x2, int x3, int x4, int x, int y, int add) {
  sum = x1 + x2 + x3 + x4;
  if (!sum) return;
  if (sum == 1) {
    if (x3 != 1) p[x][y + 1] += add;
    if (x2 != 1) p[x + 1][y] += add;
    if (x4 != 1) p[x][y] += add;
    if (x1 != 1) p[x + 1][y + 1] += add;
    return;
  }
  if (sum == 2) {
    if (x3 == 1) p[x][y + 1] += add;
    if (x2 == 1) p[x + 1][y] += add;
    if (x4 == 1) p[x][y] += add;
    if (x1 == 1) p[x + 1][y + 1] += add;
    return;
  }
  if (sum == 3) {
    if (x3 != 1) p[x][y + 1] += add;
    if (x2 != 1) p[x + 1][y] += add;
    if (x4 != 1) p[x][y] += add;
    if (x1 != 1) p[x + 1][y + 1] += add;
    return;
  }
  if (sum == 4) {
    p[x][y + 1] += add;
    p[x + 1][y] += add;
    p[x + 1][y + 1] += add;
    p[x][y] += add;
    return;
  }
}
namespace solve1 {
void main() {
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2)
      check(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1], i, j, 1);
  return;
}
}  // namespace solve1
namespace solve2 {
void main() {
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2)
      check(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1], i, j, 1);
  for (int j = 1; j < m; j += 2)
    check(0, 0, a[n][j], a[n][j + 1], n - 1, j, 10000);
  return;
}
}  // namespace solve2
namespace solve3 {
void main() {
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2)
      check(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1], i, j, 1);
  for (int i = 1; i < n; i += 2)
    check(0, a[i][m], 0, a[i + 1][m], i, m - 1, 100);
  return;
}
}  // namespace solve3
namespace solve4 {
void main() {
  for (int i = 1; i < n; i += 2)
    for (int j = 1; j < m; j += 2)
      check(a[i][j], a[i][j + 1], a[i + 1][j], a[i + 1][j + 1], i, j, 1);
  for (int j = 1; j <= m - 2; j += 2)
    check(0, 0, a[n][j], a[n][j + 1], n - 1, j, 10000);
  for (int i = 1; i <= n - 2; i += 2)
    check(0, a[i][m], 0, a[i + 1][m], i, m - 1, 100);
  check(0, 0, 0, a[n][m], n - 1, m - 1, 1000000);
  return;
}
}  // namespace solve4
void Print(int x, int y) {
  if (x % 2 == 1 && y % 2 == 1)
    printf("%d %d %d %d %d %d\n", x, y, x + 1, y, x, y + 1);
  if (x % 2 == 0 && y % 2 == 1)
    printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y + 1);
  if (x % 2 == 1 && y % 2 == 0)
    printf("%d %d %d %d %d %d\n", x, y, x, y - 1, x + 1, y);
  if (x % 2 == 0 && y % 2 == 0)
    printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y - 1);
}
void pRint(int x, int y) {
  if (y == m - 1) {
    if (x % 2 == 1)
      printf("%d %d %d %d %d %d\n", x, y, x + 1, y, x, y + 1);
    else
      printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y + 1);
  } else {
    if (x % 2 == 1)
      printf("%d %d %d %d %d %d\n", x, y, x + 1, y, x, y - 1);
    else
      printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y - 1);
  }
}
void prInt(int x, int y) {
  if (x == n - 1) {
    if (y % 2 == 1)
      printf("%d %d %d %d %d %d\n", x, y, x + 1, y, x, y + 1);
    else
      printf("%d %d %d %d %d %d\n", x, y, x, y - 1, x + 1, y);
  } else {
    if (y % 2 == 1)
      printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y + 1);
    else
      printf("%d %d %d %d %d %d\n", x, y, x - 1, y, x, y - 1);
  }
}
void priNt(int x, int y) {
  if (x == n - 1 && y == m - 1)
    printf("%d %d %d %d %d %d", x, y, x + 1, y, x, y + 1);
  if (x == n - 1 && y == m)
    printf("%d %d %d %d %d %d", x, y, x + 1, y, x, y - 1);
  if (x == n && y == m - 1)
    printf("%d %d %d %d %d %d", x, y, x - 1, y, x, y + 1);
  if (x == n && y == m) printf("%d %d %d %d %d %d", x, y, x - 1, y, x, y - 1);
}
void print() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if ((p[i][j] % 100) & 1) tot++;
      if ((p[i][j] / 100) & 1) tot++;
      if ((p[i][j] / 10000) & 1) tot++;
      if ((p[i][j] / 1000000) & 1) tot++;
    }
  printf("%d\n", tot);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if ((p[i][j] % 100) & 1) Print(i, j);
      if ((p[i][j] / 100) & 1) pRint(i, j);
      if ((p[i][j] / 10000) & 1) prInt(i, j);
      if ((p[i][j] / 1000000) & 1) priNt(i, j);
    }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    memset(p, 0, sizeof p);
    tot = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++) a[i][j + 1] = (s[j] == '1');
    }
    if (n % 2 == 0 && m % 2 == 0) solve1::main();
    if (n % 2 == 1 && m % 2 == 0) solve2::main();
    if (n % 2 == 0 && m % 2 == 1) solve3::main();
    if (n % 2 == 1 && m % 2 == 1) solve4::main();
    print();
  }
  return 0;
}
