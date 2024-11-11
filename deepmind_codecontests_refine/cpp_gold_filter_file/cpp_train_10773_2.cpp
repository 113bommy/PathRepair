#include <bits/stdc++.h>
bool visited[2510][2510];
int n, len, mul[16], sum[2510];
char str[2510 << 1], sign[2510];
unsigned long long ar[2510], dp[2510][2510];
unsigned long long F(int i, int j) {
  if (i > j) return 0;
  if (i == j) return ar[i];
  if (visited[i][j]) return dp[i][j];
  int c, d, k, l;
  unsigned long long x, r, y = sum[j], res = 0;
  if (i) y -= sum[i - 1];
  for (k = 0; k < len;) {
    if (mul[k] >= i && mul[k] < j) {
      x = ar[mul[k]] * ar[mul[k] + 1];
      y -= ar[mul[k]];
      y -= ar[mul[k] + 1];
      for (l = k + 1; l < len; l++) {
        if (mul[l] >= i && mul[l] < j && ((mul[l - 1] + 1) == mul[l])) {
          x *= ar[mul[l] + 1];
          y -= ar[mul[l] + 1];
        } else
          break;
      }
      k = l;
      res += x;
    } else
      k++;
  }
  res += y;
  visited[i][j] = true;
  return (dp[i][j] = res);
}
unsigned long long val(int i, int j) {
  int k, l, d, f, s;
  f = -1, s = -1;
  unsigned long long res = F(i, j);
  for (k = i - 1; k >= 0; k--) {
    if (sign[k] == '+') {
      f = k;
      break;
    }
  }
  if (f != -1) {
    if ((f + 1) <= (i - 1)) res *= F(f + 1, i - 1);
  } else if (i)
    res *= F(0, i - 1);
  for (k = j; (k + 1) < n; k++) {
    if (sign[k] == '+') {
      s = k;
      break;
    }
  }
  if (s != -1) {
    if ((j + 1) <= (s - 0)) res *= F(j + 1, s - 0);
  } else if ((j + 1) < n)
    res *= F(j + 1, n - 1);
  if (f != -1) res += F(0, f);
  if (s != -1) res += F(s + 1, n - 1);
  return res;
}
int main() {
  int i, j, k, l;
  unsigned long long x, y, z, r, res;
  while (scanf("%s", str) != EOF) {
    n = 0, len = 0;
    int m = strlen(str);
    for (i = 0; i < m; i += 2) {
      ar[n] = sum[n] = str[i] - 48;
      if (n) sum[n] += sum[n - 1];
      if ((i + 1) < m) {
        sign[n] = str[i + 1];
        if (sign[n] != '+') mul[len++] = n;
      }
      n++;
    }
    memset(visited, 0, sizeof(visited));
    res = F(0, n - 1);
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        x = val(i, j);
        if (x > res) res = x;
      }
    }
    printf("%I64u\n", res);
  }
  return 0;
}
