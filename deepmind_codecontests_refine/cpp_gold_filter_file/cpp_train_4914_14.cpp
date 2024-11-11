#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int a[1005], id[1005];
int ans[1005][1005];
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    int x = id[i];
    ans[i][x] = 1;
    for (int j = i + 1; j <= min(i + a[x] - 1, n + 1); j++) ans[j][x] = 1;
    for (int j = 1; j <= max(0, a[x] - (n + 2 - i)); j++) ans[j][x] = 1;
  }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
    puts("");
  }
  return 0;
}
