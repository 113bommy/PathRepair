#include <bits/stdc++.h>
using namespace std;
int a[101], b[101], c[101][101];
void do_arr(int *a, int n) {
  if (n == 1)
    a[0] = 1;
  else if (n == 2) {
    a[0] = 3;
    a[1] = 4;
  } else if (n % 2 == 0) {
    for (int i = 0; i < n - 1; i++) {
      a[i] = 1;
    }
    a[n - 1] = (n - 2) / 2;
  } else if (n % 2 != 0) {
    for (int i = 1; i < n - 1; i++) {
      a[i] = 1;
    }
    a[n - 1] = (n + 1) / 2;
    a[0] = 2;
  }
}
int main() {
  int n;
  cin >> n;
  int m;
  cin >> m;
  do_arr(a, n);
  do_arr(b, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      c[i][j] = a[i] * b[j];
    }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  return 0;
}
