#include <bits/stdc++.h>
using namespace std;
int n, a[105], p[105];
long long g[105];
long long d[105][105][105];
bool ok[105][105];
char c[105];
void read(int& x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
long long dp(int l, int r, int k) {
  if (ok[l][r]) return d[l][r][k] = g[r - l + k + 1];
  if (d[l][r][k]) return d[l][r][k];
  for (int i = l; i < r; i++) {
    d[l][r][k] = max(d[l][r][k], dp(l, i, 0) + dp(i + 1, r, k));
  }
  for (int i = l; i < r; i++) {
    if (c[i] != c[r] && c[i + 1] == c[r]) {
      d[l][r][k] =
          max(d[l][r][k], dp(l, i, k + r - p[r] + 1) + dp(i + 1, p[r] - 1, 0));
    }
  }
  return d[l][r][k];
}
int main() {
  read(n);
  scanf("%s", c + 1);
  for (int i = 1; i <= n; i++) {
    read(a[i]);
    g[i] = a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 1; j--) {
      if (c[j] == c[i]) {
        p[i] = j;
        ok[i][j] = 1;
      } else
        break;
    }
  }
  for (int i = 2; i <= n; i++)
    for (int j = 1; j < i; j++) g[i] = max(g[i], g[j] + a[i - j]);
  printf("%lld\n", dp(1, n, 0));
}
