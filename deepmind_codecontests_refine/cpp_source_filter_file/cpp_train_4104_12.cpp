#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 3;
int num2[MAXN][MAXN], num1[MAXN][MAXN];
int n, a[MAXN], tmp[MAXN], p[3 * MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    tmp[i] = a[i];
  }
  memset(num1, 0, sizeof(num1));
  long long sum = 0;
  for (int i = 1; i < n; i = i + 1) {
    int j = i;
    while (j > 0 && tmp[j] < tmp[j - 1]) {
      sum++;
      swap(tmp[j], tmp[j - 1]);
      j = j - 1;
    }
  }
  for (int i = 1; i < n; i++) {
    int x = 0;
    for (int j = i - 1; j > 0; j--) {
      if (a[j] > a[i]) num1[0][i]++;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        num1[i][j] = num1[i - 1][j] - 1;
      else
        num1[i][j] = num1[i - 1][j];
    }
  }
  memset(num2, 0, sizeof(num2));
  for (int i = 0; i < n - 1; i++) {
    if (a[0] > a[i] && a[n - 1] > a[i])
      num2[i][n - 1] = (n - 1 - a[i]) - num1[0][i] - 2;
    else if (a[0] > a[i] || a[n - 1] > a[i])
      num2[i][n - 1] = (n - 1 - a[i]) - num1[0][i] - 1;
    else
      num2[i][n - 1] = (n - 1 - a[i]) - num1[0][i];
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i - 1; j >= 0; j--) {
      if (a[i] > a[j] && num2[j][i + 1])
        num2[j][i] = num2[j][i + 1] - 1;
      else
        num2[j][i] = num2[j][i + 1];
    }
  }
  memset(p, 0, sizeof(p));
  int max = -2 * n - 2;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = 2 * num1[i][j] - 2 * num2[i][j];
      if (a[i] > a[j])
        x++;
      else if (a[i] < a[j])
        x--;
      p[x + 2 * n]++;
      if (x > max) max = x;
    }
  }
  printf("%I64d %d\n", sum - max, p[max + 2 * n]);
  return 0;
}
