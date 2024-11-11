#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 3;
int a[MAXN], b[MAXN], p[MAXN];
int read() {
  int x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * w;
}
int main() {
  int n = read(), ans = 0;
  for (int i = 1; i <= n; i++) a[i] = read(), p[a[i]] = 0;
  for (int i = 1; i <= n; i++) b[i] = read(), p[b[i]] = i;
  if (p[1]) {
    int i, j;
    for (i = 1; p[i] == p[1] + i - 1; i++)
      ;
    if (p[i - 1] == n) {
      for (j = i; j <= n && p[j] <= j - i; j++)
        ;
      if (j > n) {
        printf("%d\n", n - i + 1);
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) ans = max(ans, p[i] - (i - 1) + n);
  printf("%d\n", ans);
  return 0;
}
