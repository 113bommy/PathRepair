#include <bits/stdc++.h>
using namespace std;
int d[3010][3010];
int n, m, B[3010], A[3010], p[3010];
bool cmp(int a, int b) {
  return (A[a] - B[a] < A[b] - B[b] || (A[a] - B[a] == A[b] - B[b] && a > b));
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &A[i]);
    A[i] -= (n - 1);
  }
  for (int i = m + 1; i <= n; i++) A[i] = A[m] > 0 ? 0 : A[m];
  for (int i = 1; i <= m; i++) {
    int tp = 0;
    for (int j = n; j > i; j--) p[++tp] = j;
    sort(p + 1, p + tp + 1, cmp);
    for (int v = 1; v <= tp && B[i] < A[i]; v++) {
      int j = p[v];
      d[i][j] = 1;
      d[j][i] = -1;
      B[i]++;
      B[j]--;
      if (j > m && B[j] < A[j]) A[j] = B[j];
    }
  }
  for (int i = 1; i <= m; i++) {
    if (A[i] != B[i]) {
      printf("no");
      return 0;
    }
  }
  for (int i = m + 1; i <= n; i++) {
    if (A[i] < B[i]) {
      printf("no");
      return 0;
    }
  }
  printf("yes\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        putchar('X');
      else if (d[i][j] == 0)
        putchar('D');
      else if (d[i][j] == 1)
        putchar('W');
      else
        putchar('L');
    }
    putchar('\n');
  }
  return 0;
}
