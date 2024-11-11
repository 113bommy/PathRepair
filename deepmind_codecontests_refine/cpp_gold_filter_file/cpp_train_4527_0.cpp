#include <bits/stdc++.h>
using namespace std;
int a[1000][4];
int used[1000];
bool equal(int x[4], int y[4]) {
  for (int sh = 0; sh < 4; sh++) {
    bool b = true;
    for (int i = 0; i < 4; i++)
      if (x[i] != y[(i + sh) % 4]) {
        b = false;
        break;
      }
    if (b) return true;
  }
  return false;
}
int main(void) {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    char x[4];
    scanf(" %c%c %c%c ", &x[0], &x[1], &x[3], &x[2]);
    for (int j = 0; j < 4; j++) a[i][j] = x[j] - '0';
    if (i != n - 1) scanf("**");
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (!used[i]) {
      ans++;
      for (int j = i + 1; j < n; j++)
        if (equal(a[i], a[j])) used[j] = 1;
    }
  printf("%d\n", ans);
  return 0;
}
