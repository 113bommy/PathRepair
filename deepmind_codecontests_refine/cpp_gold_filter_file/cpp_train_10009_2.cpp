#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000 + 5;
int n, m, a[MAX][MAX], row[MAX][MAX], col[MAX][MAX];
int r[MAX], c[MAX];
int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
        row[i][j] = a[i][j];
      }
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) col[i][j] = a[j][i];
    for (int i = 0; i < n; i++) {
      sort(row[i], row[i] + m);
      r[i] = unique(row[i], row[i] + m) - row[i];
    }
    for (int i = 0; i < m; i++) {
      sort(col[i], col[i] + n);
      c[i] = unique(col[i], col[i] + n) - col[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = upper_bound(row[i], row[i] + r[i], a[i][j]) - row[i];
        int y = upper_bound(col[j], col[j] + c[j], a[i][j]) - col[j];
        printf("%d ", max(max(x + c[j] - y, y + r[i] - x), max(r[i], c[j])));
      }
      printf("\n");
    }
  }
  return 0;
}
