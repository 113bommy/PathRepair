#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 5;
int a[N];
char c[N];
int re() {
  char c = getchar();
  int all = 0, pd = 1;
  for (; c > '9' || c < '0'; c = getchar())
    if (c == '-') pd = -1;
  while (c >= '0' && c <= '9') all = all * 10 + c - '0', c = getchar();
  return all * pd;
}
int main() {
  int T = re();
  while (T--) {
    int n = re();
    scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) a[i] = c[i] - '0';
    int flag = 0;
    for (int i = 1; i <= (n + 1) / 2; i++) {
      if (a[i] == 0) {
        printf("%d %d %d %d\n", i, n, i + 1, n);
        flag = 1;
        break;
      } else if (a[n - i + 1] == 0) {
        int t = n - i + 1;
        printf("%d %d %d %d\n", 1, t, 1, t - 1);
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      printf("%d %d %d %d\n", 1, n - 1, 2, n);
    }
  }
}
