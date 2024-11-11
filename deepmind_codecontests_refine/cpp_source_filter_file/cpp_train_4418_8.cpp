#include <bits/stdc++.h>
const int INF = 1e9;
const int N = 312312;
const double PI = 3.1415926535897932384626433832795;
using namespace std;
double a[190][190];
int n, m, c, i;
int main() {
  ios_base ::sync_with_stdio();
  scanf("%d", &n);
  for (c = 1; c <= n; c++) {
    for (i = 1; i <= n; i++) {
      scanf("%lf", &a[c][i]);
    }
  }
  for (c = 1; c <= n; c++) {
    for (i = 1; i <= n; i++) {
      printf("%.16lf", (a[c][i] + a[i][c]) / 2);
    }
    printf("\n");
  }
  for (c = 1; c <= n; c++) {
    for (i = 1; i <= n; i++) {
      printf("%.16lf", (a[c][i] - a[i][c]) / 2);
    }
    printf("\n");
  }
  return 0;
}
