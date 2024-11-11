#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  char str[n][m + 1];
  gets(str[0]);
  for (int i = 0; i < n; i++) gets(str[i]);
  int maxIndex[n];
  int minIndex[n];
  for (int i = 0; i < n; i++) {
    int minInd = m, maxInd = -1;
    for (int j = 0; j < m; j++) {
      if (str[i][j] == 'W') {
        minInd = min(minInd, j);
        maxInd = max(maxInd, j);
      }
    }
    maxIndex[i] = maxInd;
    minIndex[i] = minInd;
  }
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    if (maxIndex[i] != -1) maxi = i;
  }
  int curj = 0;
  int dir = 1;
  int ans = 0;
  for (int i = 0; i <= maxi; i++, dir = 1 - dir) {
    if (dir) {
      if (i == maxi)
        ans += max(maxIndex[i], curj) - curj;
      else {
        int newj = max(curj, max(maxIndex[i], maxIndex[i + 1]));
        ans += newj - curj + 1;
        curj = newj;
      }
    } else {
      if (i == maxi)
        ans += curj - min(minIndex[i], curj);
      else {
        int newj = min(curj, min(minIndex[i], minIndex[i + 1]));
        ans += curj - newj + 1;
        curj = newj;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
