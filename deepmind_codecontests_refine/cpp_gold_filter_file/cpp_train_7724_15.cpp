#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 10;
const long long B = 98765431;
int a[N], b[N][N];
long long val[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) b[i + 1][j] = (a[j] >= i);
    for (int j = 1; j < i; j++) val[i + 1] = val[i + 1] * B + b[i + 1][j];
    int p = 0;
    for (int j = 1; j <= i; j++)
      if (val[j] == val[i + 1]) p = j;
    int x = min(a[i], i);
    if (p) b[p][i] = 1, x--;
    for (int j = 1; j <= i + 1; j++)
      if (j != p) {
        if (x)
          b[j][i] = 1, x--;
        else
          b[j][i] = 0;
      }
    for (int j = 1; j <= i + 1; j++) val[j] = val[j] * B + b[j][i];
  }
  printf("%d\n", n + 1);
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n; j++) printf("%d", b[i][j]);
    printf("\n");
  }
}
