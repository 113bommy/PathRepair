#include <bits/stdc++.h>
const int N = 110;
const int inf = 0x3f3f3f3f;
using namespace std;
int a[N][N], n, r[N], c[N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) r[i] += a[i][j], c[j] += a[i][j];
  int ret = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (r[i] > c[j]) ret++;
  printf("%d\n", ret);
  return 0;
}
