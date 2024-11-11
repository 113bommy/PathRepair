#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 3, b = 2, c = 3, arr[150][150] = {0}, k, m, l, i, j;
  scanf("%d", &n);
  while (a + c <= n) {
    a += c;
    b++;
    c++;
  }
  k = 0;
  m = 1;
  l = 1;
  while (k != b) {
    for (j = k; j < b; j++) {
      arr[k][j] = l;
      l++;
    }
    l = m;
    for (i = k + 1; i <= b; i++) {
      arr[i][k] = l;
      l++;
    }
    m = l;
    k++;
  }
  printf("%d\n", b + 1);
  for (i = 0; i <= b; i++) {
    for (j = 0; j < b; j++) {
      if (j != b - 1)
        printf("%d ", arr[i][j]);
      else
        printf("%d\n", arr[i][j]);
    }
  }
  return 0;
}
