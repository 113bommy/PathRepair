#include <bits/stdc++.h>
using namespace std;
int reader_pt = 1048576, reader_last;
char reader_buf[1048576];
void reader(int *x) {
  int k, m = 0;
  *x = 0;
  for (;;) {
    {
      if (reader_pt == 1048576)
        reader_pt = 0,
        reader_last = fread(reader_buf, sizeof(char), 1048576, stdin);
      (k) = reader_buf[reader_pt++];
    };
    if (k == '-') {
      m = 1;
      break;
    }
    if ('0' <= k && k <= '9') {
      *x = k - '0';
      break;
    }
  }
  for (;;) {
    {
      if (reader_pt == 1048576)
        reader_pt = 0,
        reader_last = fread(reader_buf, sizeof(char), 1048576, stdin);
      (k) = reader_buf[reader_pt++];
    };
    if (k < '0' || k > '9') break;
    *x = (*x) * 10 + k - '0';
  }
  if (m) (*x) = -(*x);
}
void reader(int *x, int *y, int *z) {
  reader(x);
  reader(y);
  reader(z);
}
int X, K, P_;
double P;
int val[256 + 1];
double dp[256][256], nx[256][256];
int main() {
  int i, j, k;
  double res;
  for (i = 1; i < 256 + 1; i++) {
    j = i;
    k = 0;
    while (j % 2 == 0) k++, j /= 2;
    val[i] = k;
  }
  reader(&X, &K, &P_);
  P = P_ / 100.0;
  for (i = 0; i < 256; i++)
    for (j = 0; j < 256; j++) dp[i][j] = 0;
  if (X % 256 == 0) {
    k = 0;
    while (X % 2 == 0) X /= 2, k++;
    dp[k][0] = 1;
  } else {
    k = X % 256;
    X /= 256;
    j = 0;
    while (X % 2 == 1) j++, X /= 2;
    dp[j][k] = 1;
  }
  while (K--) {
    for (i = 0; i < 256; i++)
      for (j = 0; j < 256; j++) nx[i][j] = 0;
    for (i = 0; i < 256; i++)
      for (j = 0; j < 256; j++)
        if (dp[i][j]) {
          if (j == 0) {
            nx[i + 1][j] += dp[i][j] * P;
            nx[0][1] += dp[i][j] * (1 - P);
            continue;
          }
          if (j * 2 > 256)
            nx[i + 1][j * 2 % 256] += dp[i][j] * P;
          else if (j * 2 == 256)
            nx[val[256]][0] += dp[i][j] * P;
          else
            nx[0][j * 2] += dp[i][j] * P;
          if (j != 256 - 1)
            nx[i][j + 1] += dp[i][j] * (1 - P);
          else
            nx[val[256] + i][0] += dp[i][j] * (1 - P);
        }
    for (i = 0; i < 256; i++)
      for (j = 0; j < 256; j++) dp[i][j] = nx[i][j];
  }
  res = 0;
  for (i = 0; i < 256; i++)
    for (j = 0; j < 256; j++)
      if (dp[i][j]) {
        if (j == 0)
          k = i;
        else
          k = val[j];
        res += dp[i][j] * k;
      }
  printf("%.9f\n", res);
  return 0;
}
