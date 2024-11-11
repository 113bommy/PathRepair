#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, MOD = (1e9) + 7;
int n, m, k, A[N + 9][N + 9], row[N + 9], col[N + 9], x, y;
char c;
void init() {
  for (int i = 0; i < N + 5; ++i) row[i] = col[i] = i;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  init();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) scanf("%d", &A[i][j]);
  }
  for (int i = 0; i < k; ++i) {
    cin.ignore();
    scanf("%c %d %d", &c, &x, &y);
    switch (c) {
      case 'c':
        swap(col[x], col[y]);
        break;
      case 'r':
        swap(row[x], row[y]);
        break;
      case 'g':
        printf("%d\n", A[col[x]][row[y]]);
    }
  }
  return 0;
}
