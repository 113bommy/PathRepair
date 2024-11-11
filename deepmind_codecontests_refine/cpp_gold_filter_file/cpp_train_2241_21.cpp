#include <bits/stdc++.h>
using namespace std;
const int maxn = 26;
const int maxm = 120;
int a, b, c, d, n, x, y, p;
int data[maxn];
char str[maxm][maxm];
void input() {
  scanf("%d%d%d%d%d", &a, &b, &c, &d, &n);
  for (int i = 0; i < n; i++) scanf("%d", &data[i]);
}
void solve() {
  for (int i = 1; i <= max(b, d); i++)
    for (int j = 1; j <= a + c; j++) str[i][j] = '.';
  if (a & 1)
    x = 1, y = b, p = -1;
  else
    x = 1, y = 1, p = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < data[i]; j++) {
      str[y][x] = 'a' + i;
      y += p;
      if (y == 0)
        x++, y = 1, p = -p;
      else if (x <= a && y > b)
        x++, y = b, p = -p;
      else if (x > a && y > d)
        x++, y = d, p = -p;
    }
  }
  printf("YES\n");
  for (int i = 1; i <= max(b, d); i++) {
    for (int j = 1; j <= a + c; j++) printf("%c", str[i][j]);
    printf("\n");
  }
}
int main() {
  input();
  solve();
  return 0;
}
