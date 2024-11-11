#include <bits/stdc++.h>
using namespace std;
int get() {
  char ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  if (ch == '-') {
    int s = 0;
    while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
    return -s;
  }
  int s = ch - '0';
  while (ch = getchar(), ch >= '0' && ch <= '9') s = s * 10 + ch - '0';
  return s;
}
const int N = 1005;
int n;
int a[N];
bool vis[N];
int k, b[N];
char ans[N][N];
void arrange(int c, int x, int y) {
  if (x < y)
    ans[c][x] = ans[c][y] = '/';
  else
    ans[c][x] = ans[c][y] = '\\';
}
int k1, b1[N];
int main() {
  n = get();
  for (int i = 1; i <= n; i++) a[i] = get();
  bool pd = 1;
  for (int i = 1; i <= n; i++) pd &= (a[i] == i);
  if (pd) {
    printf("%d\n", n);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) putchar('.');
      putchar('\n');
    }
  } else {
    int w = n, key = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) ans[i][j] = '.';
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        if (i == a[i]) continue;
        k = 0;
        for (int x = i; !vis[x]; x = a[x]) vis[b[++k] = x] = 1;
        if (!key) {
          k1 = k;
          for (int x = 1; x <= k; x++) b1[x] = b[x];
          key = i;
        } else {
          int st = w;
          ans[st][1] = '\\';
          for (int x = k; x >= 2; x--) {
            arrange(w, b[x], b[x % k + 1]);
            w--;
          }
          arrange(w, key, a[i]);
          w--;
        }
      }
    for (int x = k1; x >= 2; x--) {
      arrange(w, b1[x], b1[x % k1 + 1]);
      w--;
    }
    printf("%d\n", n - 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) putchar(ans[i][j]);
      putchar('\n');
    }
  }
  return 0;
}
