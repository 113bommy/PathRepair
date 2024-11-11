#include <bits/stdc++.h>
int abs(int a) {
  if (a < 0) return -a;
  return a;
}
int max(int a, int b) {
  if (a < b) return b;
  return a;
}
int min(int a, int b) {
  if (a > b) return b;
  return a;
}
int main() {
  int n, m, i, j, a, b;
  scanf("%d %d %d %d %d %d", &n, &m, &i, &j, &a, &b);
  if ((i == 1 || i == n) && (j == 1 || j == m)) {
    printf("0\n");
    return 0;
  }
  if ((a > (n - i) && a > (i - 1)) || (b > (m - j) && b > (j - 1))) {
    printf("Poor Inna and pony!\n");
    return 0;
  }
  int resp = 1000000;
  if ((n - i) % a == 0 && (m - j) % b == 0) {
    if (abs((n - i) / a - (m - j) / b) % 2 == 0) {
      int aux = max((n - i) / a, (m - j) / b);
      resp = min(resp, aux);
    }
  }
  if ((i - 1) % a == 0 && (m - j) % b == 0) {
    if (abs((i - 1) / a - (m - j) / b) % 2 == 0) {
      int aux = max((i - 1) / a, (m - j) / b);
      resp = min(resp, aux);
    }
  }
  if ((n - i) % a == 0 && (j - 1) % b == 0) {
    if (abs((n - i) / a - (j - 1) / b) % 2 == 0) {
      int aux = max((n - i) / a, (j - 1) / b);
      resp = min(resp, aux);
    }
  }
  if ((i - 1) % a == 0 && (j - 1) % b == 0) {
    if (abs((i - 1) / a - (j - 1) / b) % 2 == 0) {
      int aux = max((i - 1) / a, (j - 1) / b);
      resp = min(resp, aux);
    }
  }
  if (resp == -1)
    printf("Poor Inna and pony!\n");
  else
    printf("%d\n", resp);
  return 0;
}
