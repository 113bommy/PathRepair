#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sum = 0, ans = 0, i, j, k;
  int a, b, c;
  scanf("%d %d", &n, &m);
  int mat[n];
  for (i = 0; i < n; i++) mat[i] = 0;
  for (i = 0; i < m; i++) {
    scanf("%d %d %d", &a, &b, &c);
    mat[a - 1] -= c;
    mat[b - 1] += c;
  }
  for (i = 0; i < n; i++)
    if (mat[i] > 0) ans += mat[i];
  printf("%d\n", ans);
  return 0;
}
