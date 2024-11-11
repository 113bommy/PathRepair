#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long a[N][N];
int n, m;
int main() {
  cin >> n;
  int x, y;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        x = i;
        y = j;
      }
    }
  }
  if (n == 1) {
    printf("1\n");
    return 0;
  }
  long long sum1, sum2, sum3, sum4;
  sum1 = sum2 = sum3 = sum4 = 0;
  int in;
  for (int i = 1; i <= n; i++) {
    if (i != x) {
      in = i;
      break;
    }
  }
  long long sum = 0;
  long long ss = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[in][i];
  }
  long long xx;
  for (int i = 1; i <= n; i++) {
    ss += a[x][i];
  }
  xx = sum - ss;
  if (xx <= 0) {
    printf("-1\n");
    return 0;
  }
  a[x][y] = xx;
  int f = 0;
  ss = 0;
  for (int i = 1; i <= n; i++) {
    ss += a[i][i];
  }
  if (ss != sum) {
    printf("-1\n");
    return 0;
  }
  ss = 0;
  for (int i = 1; i <= n; i++) {
    ss += a[i][n + 1 - i];
  }
  if (ss != sum) {
    printf("-1\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    ss = 0;
    for (int j = 1; j <= n; j++) {
      ss += a[i][j];
    }
    if (ss != sum) {
      printf("-1\n");
      return 0;
    }
  }
  for (int j = 1; j <= n; j++) {
    ss = 0;
    for (int i = 1; i <= n; i++) {
      ss += a[i][j];
    }
    if (ss != sum) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%lld\n", xx);
  return 0;
}
