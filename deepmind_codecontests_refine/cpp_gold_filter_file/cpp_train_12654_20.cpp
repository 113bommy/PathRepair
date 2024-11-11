#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
long long a[505][505];
int n;
long long sumr[505], sumc[505], sumda, sumdb;
long long tsumr, tsumc;
int r, c;
int main(void) {
  scanf("%d", &n);
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      scanf("%I64d", &a[i][j]);
      if (a[i][j] == 0) r = i, c = j;
      sumr[i] += a[i][j];
      sumc[j] += a[i][j];
      if (i == j) sumda += a[i][j];
      if (j == n - i - 1) sumdb += a[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i != r) {
      tsumr = sumr[i];
      break;
    }
  }
  a[r][c] = tsumr - sumr[r];
  sumr[r] += a[r][c];
  sumc[c] += a[r][c];
  for (long long i = 0, flag = 0, sum; i < n; ++i) {
    if (flag == 0)
      flag = 1, tsumr = sum = sumr[i];
    else if (sumr[i] != sum) {
      printf("-1\n");
      return 0;
    }
  }
  for (long long i = 0, flag = 0, sum; i < n; ++i) {
    if (flag == 0)
      flag = 1, tsumc = sum = sumc[i];
    else if (sumc[i] != sum || sum != tsumr) {
      printf("-1\n");
      return 0;
    }
  }
  if (r == c) sumda += a[r][c];
  if (sumda != tsumr) {
    printf("-1\n");
    return 0;
  }
  if (c == n - r - 1) sumdb += a[r][c];
  if (sumdb != tsumr) {
    printf("-1\n");
    return 0;
  }
  if (a[r][c] <= 0) {
    printf("-1\n");
    return 0;
  }
  printf("%I64d\n", a[r][c]);
  return 0;
}
