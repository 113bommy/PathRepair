#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 5;
char x[MAXN][MAXN];
int n, ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", &x[i]);
  }
  bool clmn[MAXN] = {0}, rw[MAXN] = {0}, diag[MAXN] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      if (i < j) {
        if (x[i][j] - '0' != (clmn[j] ^ rw[i])) {
          rw[i] = !rw[i];
          clmn[j] = !clmn[j];
          diag[i] = !diag[i];
          diag[j] = !diag[j];
          ans++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    clmn[i] = rw[i] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      if (i > j) {
        if (x[i][j] - '0' != (clmn[j] ^ rw[i])) {
          rw[i] = !rw[i];
          clmn[j] = !clmn[j];
          diag[i] = !diag[i];
          diag[j] = !diag[j];
          ans++;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (x[i][i] - '0' != diag[i]) {
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
