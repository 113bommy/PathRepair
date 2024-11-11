#include <bits/stdc++.h>
using namespace std;
const int MAX_N = int(1e6) + 10;
const int MAX_M = 21;
int n, r, c;
int a[MAX_N], b[MAX_N];
int f[MAX_N][MAX_M];
char buffer[MAX_N * 6];
int main() {
  scanf("%d%d%d\n", &n, &r, &c);
  c++;
  gets(buffer);
  int m = strlen(buffer);
  buffer[m++] = ' ';
  for (int i = 0, j = 0; i < n; i++, j++) {
    b[i] = j;
    for (a[i] = 0; j < m && buffer[j] != ' '; j++, a[i]++)
      ;
  }
  b[n] = m;
  for (int i = 0, j = 0, sum = 0; i < n; i++) {
    for (; j < n && sum + a[j] + 1 <= c; sum += a[j++] + 1)
      ;
    f[i][0] = j - i;
    if (i < j) {
      sum -= a[i] + 1;
    } else {
      j++;
    }
  }
  for (int j = 1; 1 << j <= r; j++) {
    for (int i = 0; i < n; i++) {
      f[i][j] = f[i][j - 1] + f[i + f[i][j - 1]][j - 1];
    }
  }
  int result = 0, start = 0, l = 0;
  for (; 1 << l <= r; l++)
    ;
  for (int i = 0; i < n; i++) {
    int sum = 0, tmp = r;
    for (int k = l; k >= 0; k--) {
      if (tmp - (1 << k) >= 0) {
        sum += f[i + sum][k];
        tmp -= 1 << k;
      }
    }
    if (sum > result) {
      result = sum;
      start = i;
    }
  }
  for (int i = 0, p = start; i < r; i++) {
    int sum = 0;
    for (; p < n && (sum + a[p] + 1) <= c; sum += a[p++] + 1) {
      if (sum > 0) {
        putchar(' ');
      }
      for (int j = b[p]; j < b[p + 1] - 1; j++) {
        putchar(buffer[j]);
      }
    }
    if (sum > 0) {
      puts("");
    }
  }
}
