#include <bits/stdc++.h>
using namespace std;
const int maxN = 3e5 + 10;
int n, a[4][maxN], tri, oth;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[0][i], &a[1][i]);
    a[2][i] = a[0][i] + a[1][i];
    a[3][i] = a[0][i] - a[1][i];
  }
  for (int i = 0; i < 4; ++i) sort(a[i] + 1, a[i] + 1 + n);
  tri = max(max(a[2][n] - a[0][1] - a[1][1], a[0][n] + a[1][n] - a[2][1]),
            max(a[0][n] - a[1][1] - a[3][1], a[3][n] - a[0][1] + a[1][n]));
  printf("%d ", tri * 2);
  oth = a[0][n] + a[1][n] - a[0][1] - a[1][1];
  oth *= 2;
  for (int i = 4; i <= n; ++i) printf("%d ", oth);
}
