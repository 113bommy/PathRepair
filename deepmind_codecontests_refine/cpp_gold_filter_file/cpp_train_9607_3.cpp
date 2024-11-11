#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int T, n, m;
char A[N][N];
void solve() {
  scanf("%d%d", &n, &m);
  int sum = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> A[i][j];
      if (A[i][j] == '1') sum++;
    }
  printf("%d\n", sum * 3);
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++) {
      if (A[i][j] == '1') {
        printf("%d %d %d %d %d %d\n", i, j, i + 1, j, i, j + 1);
        printf("%d %d %d %d %d %d\n", i, j, i + 1, j, i + 1, j + 1);
        printf("%d %d %d %d %d %d\n", i, j, i, j + 1, i + 1, j + 1);
      }
    }
  for (int i = 1; i < n; i++)
    if (A[i][m] == '1') {
      printf("%d %d %d %d %d %d\n", i, m, i, m - 1, i + 1, m);
      printf("%d %d %d %d %d %d\n", i, m, i, m - 1, i + 1, m - 1);
      printf("%d %d %d %d %d %d\n", i, m, i + 1, m, i + 1, m - 1);
    }
  for (int j = 1; j < m; j++)
    if (A[n][j] == '1') {
      printf("%d %d %d %d %d %d\n", n, j, n, j + 1, n - 1, j);
      printf("%d %d %d %d %d %d\n", n, j, n, j + 1, n - 1, j + 1);
      printf("%d %d %d %d %d %d\n", n, j, n - 1, j, n - 1, j + 1);
    }
  if (A[n][m] == '1') {
    printf("%d %d %d %d %d %d\n", n, m, n - 1, m, n, m - 1);
    printf("%d %d %d %d %d %d\n", n, m, n - 1, m, n - 1, m - 1);
    printf("%d %d %d %d %d %d\n", n, m, n, m - 1, n - 1, m - 1);
  }
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
