#include <bits/stdc++.h>
using namespace std;
const int MAX = 55;
int n;
int a[2][MAX], b[MAX];
int main() {
  scanf("%d", &n);
  for (int j = (0); j < (2); ++j)
    for (int i = (0); i < (n - 1); ++i) scanf("%d", &a[j][i]);
  for (int i = (0); i < (n); ++i) scanf("%d", &b[i]);
  for (int j = (0); j < (2); ++j)
    for (int i = (1); i < (n - 1); ++i) a[j][i] += a[j][i - 1];
  int sol = 100 * MAX;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j)
      if (i != j) {
        int cur = b[i] + b[j];
        if (i) cur += a[0][i - 1];
        if (j) cur += a[0][j - 1];
        cur += max(0, a[1][n - 2] - (i ? a[1][i - 1] : 0));
        cur += max(0, a[1][n - 2] - (j ? a[1][j - 1] : 0));
        sol = min(sol, cur);
      }
  printf("%d\n", sol);
  return 0;
}
