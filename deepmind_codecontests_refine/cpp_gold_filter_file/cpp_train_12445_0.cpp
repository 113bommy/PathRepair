#include <bits/stdc++.h>
using namespace std;
int form[501][501];
int nform[501][501];
int A[501];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  form[0][0] = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
    for (int j = 0; j < 501; j++) {
      for (int kk = 0; kk < 501; kk++) {
        if (j - A[i] >= 0) nform[j][kk] |= form[j - A[i]][kk];
        if (kk - A[i] >= 0) nform[j][kk] |= form[j][kk - A[i]];
      }
    }
    for (int j = 0; j < 501; j++) {
      for (int kk = 0; kk < 501; kk++) {
        form[j][kk] |= nform[j][kk];
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= k; i++) {
    if (form[i][k - i]) ans++;
  }
  printf("%d\n", ans);
  for (int i = 0; i <= k; i++) {
    if (form[i][k - i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
}
