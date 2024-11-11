#include <bits/stdc++.h>
using namespace std;
int A[100][100][100];
int n, m, k;
bool OK(int i, int j, int p) {
  if ((i >= 0) && (j >= 0) && (p >= 0) && (i < n) && (j < m) && (p < k)) {
    return A[i][j][p];
  } else {
    return false;
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char s[101];
      scanf("%s", s);
      for (int p = 0; p < k; p++) {
        A[i][j][p] = s[p] == '1';
      }
    }
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int p = 0; p < k; p++) {
        if (A[i][j][p]) {
          int level = 0;
          if (OK(i - 1, j, p) && OK(i + 1, j, p)) level++;
          if (OK(i, j - 1, p) && OK(i, j + 1, p)) level++;
          if (OK(i, j, p - 1) && OK(i, j, p + 1)) level++;
          if (OK(i - 1, j, p) && OK(i, j + 1, p) && !OK(i - 1, j + 1, p))
            level++;
          if (OK(i - 1, j, p) && OK(i, j, p + 1) && !OK(i - 1, j, p + 1))
            level++;
          if (OK(i, j - 1, p) && OK(i + 1, j, p) && !OK(i + 1, j - 1, p))
            level++;
          if (OK(i, j - 1, p) && OK(i, j, p + 1) && !OK(i, j - 1, p + 1))
            level++;
          if (OK(i, j, p - 1) && OK(i, j + 1, p) && !OK(i, j + 1, p - 1))
            level++;
          if (OK(i, j, p - 1) && OK(i + 1, j, p) && !OK(i + 1, j, p - 1))
            level++;
          if (level) {
            count++;
          }
        }
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
