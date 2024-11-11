#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, x[3], y[3], cell[N][N], ans;
int main() {
  scanf("%d", &n);
  for (int z = 0; z < (n); z++) {
    scanf("%d %d %d %d", &x[1], &y[1], &x[2], &y[2]);
    if (x[2] < x[1]) swap(x[1], x[2]);
    if (y[2] < y[1]) swap(y[1], y[2]);
    for (int i = x[1]; i <= x[2]; i++) {
      for (int j = y[1]; j <= y[2]; j++) {
        cell[i][j]++;
      }
    }
  }
  for (int i = 0; i < (101); i++) {
    for (int j = 0; j < (101); j++) {
      ans += cell[i][j];
    }
  }
  printf("%d\n", ans);
  return 0;
}
