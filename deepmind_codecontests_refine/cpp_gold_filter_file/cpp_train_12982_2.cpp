#include <bits/stdc++.h>
int min(int a, int b) { return a > b ? b : a; }
int max(int a, int b) { return a < b ? b : a; }
void swap(int* a, int* b) { *a = *a + *b - (*b = *a); }
int a[5010];
int ans;
int F[5010][5010];
int maxs[5010][5010];
int l[100001];
int r[100001];
int main() {
  int i, j, k;
  int n;
  int q;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 1; i <= n; i++) {
    F[i][i] = a[i];
    maxs[i][i] = a[i];
  }
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%d", &l[i]);
    scanf("%d", &r[i]);
  }
  for (j = 2; j <= n; j++)
    for (i = j - 1; i >= 1; --i) {
      int max2 = max(maxs[i][j - 1], maxs[i + 1][j]);
      F[i][j] = F[i + 1][j] ^ F[i][j - 1];
      maxs[i][j] = max(max2, F[i][j]);
    }
  for (i = 1; i <= q; i++) {
    printf("%d\n", maxs[l[i]][r[i]]);
  }
}
