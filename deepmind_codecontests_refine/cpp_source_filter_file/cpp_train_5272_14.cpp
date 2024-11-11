#include <bits/stdc++.h>
using namespace std;
int tr[100010];
int tmp[100010];
int main() {
  int n, m;
  int swp = 0;
  scanf("%d %d", &n, &m);
  if (n <= 2 && m <= 2) {
    if (n == 1 && m == 1)
      printf("YES\n1\n");
    else
      printf("NO\n");
    return 0;
  }
  if (n <= 2 && m == 3) {
    printf("NO\n");
    return 0;
  }
  if (n == 3 && m <= 2) {
    printf("NO\n");
    return 0;
  }
  printf("YES\n");
  if (n == 3 && m == 3) {
    printf("5 1 8\n");
    printf("3 9 4\n");
    printf("7 2 6\n");
    return 0;
  }
  for (int i = 0; i < n * m; i++) tr[i] = i + 1;
  if (n > m) {
    swp = 1;
    for (int i = 0; i < n * m; i++) tr[i] = ((i % n) * m) + (i / n) + 1;
    swap(n, m);
  }
  vector<vector<int> > ans(n, vector<int>(m, 0));
  if (n == 3) {
    for (int j = 1; j < m; j += 2) ans[0][j / 2] = 0 * m + j;
    for (int j = 0; j < m; j += 2) ans[0][j / 2 + m / 2] = 0 * m + j;
    if (m & 1) {
      for (int j = 0; j < m; j += 2) ans[1][j / 2] = 2 * m + j;
      for (int j = 1; j < m; j += 2) ans[1][j / 2 + (m + 1) / 2] = 2 * m + j;
    } else {
      for (int j = 0; j < m; j += 2) ans[1][j / 2] = 2 * m + m - j - 2;
      for (int j = 1; j < m; j += 2)
        ans[1][j / 2 + (m + 1) / 2] = 2 * m + m - j;
    }
    for (int j = 1; j < m; j += 2) ans[2][j / 2] = 1 * m + j;
    for (int j = 0; j < m; j += 2) ans[2][j / 2 + m / 2] = 1 * m + j;
  } else {
    for (int i = 0; i < n; i += 2) {
      if (i + 1 == n) {
        for (int k = n - 1; k >= 1; k--)
          for (int l = 0; l < m; l++) ans[k][l] = ans[k - 1][l];
        for (int j = 0; j < m; j += 2) ans[0][j / 2] = i * m + j;
        for (int j = 1; j < m; j += 2) ans[0][j / 2 + (m + 1) / 2] = i * m + j;
        break;
      }
      for (int j = 0; j < m; j += 2) ans[i][j] = j + i * m;
      for (int j = 1; j < m; j += 2) ans[i + 1][j] = j + i * m;
      if (m & 1) {
        for (int j = 0; j < m / 2; j++) tmp[j] = (i + 1) * m + m - j - 1;
        for (int j = m / 2; j < m; j++) tmp[j] = (i + 1) * m + j - m / 2;
      } else {
        for (int j = 0; j < m / 2; j++) tmp[j] = (i + 1) * m + m / 2 + j;
        for (int j = m / 2; j < m; j++) tmp[j] = (i + 1) * m + j - m / 2;
      }
      for (int j = 1; j < m; j += 2) ans[i][j] = tmp[j];
      for (int j = 0; j < m; j += 2) ans[i + 1][j] = tmp[j];
    }
  }
  if (swp) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) printf("%d ", tr[ans[j][i]]);
      printf("\n");
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) printf("%d ", tr[ans[i][j]]);
    printf("\n");
  }
  return 0;
}
