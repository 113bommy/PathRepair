#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 100 + 10;
int main() {
  int x, y, a, b, n = 0;
  int ans[2][MAXSIZE * MAXSIZE];
  scanf("%d%d%d%d", &x, &y, &a, &b);
  for (int i = a; i <= x; i++)
    for (int j = b; j < i && j <= y; j++) ans[0][n] = i, ans[1][n] = j, n++;
  printf("%d\n", n);
  for (int i = 0; i < n; i++) printf("%d %d\n", ans[0][i], ans[1][i]);
  return 0;
}
