#include <bits/stdc++.h>
using namespace std;
const double pi = acos(double(-1.0));
int n, m;
double p[510][2];
void dfs(int k, int i) {
  if (k > n) return;
  if (k % 2 == 1) {
    printf("%d ", i);
    dfs(k + 1, i + 3);
    printf("%d %d %d %d ", i + 3, i + 2, i + 1, i + 4);
  } else {
    printf("%d ", i);
    dfs(k + 1, i + 4);
    printf("%d %d %d %d ", i + 4, i + 1, i + 2, i + 3);
  }
}
int main() {
  scanf("%d", &n);
  m = 1;
  p[1][0] = p[1][1] = 0;
  double c36 = cos(pi / 5), s36 = sin(pi / 5);
  double c72 = cos(2 * pi / 5), s72 = sin(2 * pi / 5);
  for (int i = 1; i <= n; i++)
    if (i % 2 == 1) {
      p[m + 1][0] = -10 * c36;
      p[m + 2][0] = 10 * c36;
      p[m + 3][0] = -5;
      p[m + 4][0] = 5;
      p[m + 1][1] = p[m + 2][1] = p[m][1] + 10 * s36;
      p[m + 3][1] = p[m + 4][1] = p[m][1] + 10 * (s36 + s72);
      m += 4;
    } else {
      p[m + 1][0] = -10 * c36;
      p[m + 2][0] = 10 * c36;
      p[m + 3][0] = 0;
      p[m + 1][1] = p[m + 2][1] = p[m][1] + 10 * s72;
      p[m + 3][1] = p[m][1] + 10 * (s72 + s36);
      m += 3;
    }
  printf("%d\n", m);
  for (int i = 1; i <= m; i++) printf("%.12lf %.12lf\n", p[i][0], p[i][1]);
  for (int i = 1, j = 1; i <= n; i++)
    if (i % 2 == 1) {
      printf("%d %d %d %d %d\n", j, j + 3, j + 2, j + 1, j + 4);
      j += 3;
    } else {
      printf("%d %d %d %d %d\n", j, j + 4, j + 1, j + 2, j + 3);
      j += 4;
    }
  dfs(1, 1);
  printf("1\n");
  return 0;
}
