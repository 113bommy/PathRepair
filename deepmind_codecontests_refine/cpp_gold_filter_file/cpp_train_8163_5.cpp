#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 7;
int a[5000][5000], n, x, Sum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) scanf("%d", a[i] + j);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) Sum += (a[i][j] * a[j][i]) % 2, Sum %= 2;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (x == 3)
      printf("%d", Sum);
    else
      scanf("%d", &x), Sum++, Sum %= 2;
  }
  return 0;
}
