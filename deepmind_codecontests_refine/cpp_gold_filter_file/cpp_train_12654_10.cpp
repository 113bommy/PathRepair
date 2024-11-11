#include <bits/stdc++.h>
using namespace std;
long long a[505][505];
long long sum, k, n, r, c;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 0) {
        r = i, c = j;
      }
    }
  }
  if (n == 1) {
    puts("1");
    return 0;
  }
  for (int j = 0; j < n; j++) {
    sum += a[(r + 1) % n][j];
    k += a[r][j];
  }
  a[r][c] = sum - k;
  if (a[r][c] <= 0) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    k = 0;
    for (int j = 0; j < n; j++) k += a[i][j];
    if (k != sum) {
      puts("-1");
      return 0;
    }
    k = 0;
    for (int j = 0; j < n; j++) k += a[j][i];
    if (k != sum) {
      puts("-1");
      return 0;
    }
  }
  k = 0;
  for (int i = 0; i < n; i++) k += a[i][i];
  if (k != sum) {
    puts("-1");
    return 0;
  }
  k = 0;
  for (int i = 0; i < n; i++) k += a[i][n - i - 1];
  if (k != sum) {
    puts("-1");
    return 0;
  }
  printf("%I64d", a[r][c]);
  return 0;
}
