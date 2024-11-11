#include <bits/stdc++.h>
using namespace std;
const long double pi = acosl(-1);
const int maxn = 210;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
const long double eps = 1e-10;
int a[maxn][maxn], n;
int main() {
  a[0][0] = 1, a[1][1] = 1;
  for (int i = 2; i < 160; i++) {
    for (int j = 1; j < i + 1; j++) a[i][j] = a[i - 1][j - 1];
    for (int j = 0; j < i + 1; j++) a[i][j] = (a[i][j] + a[i - 2][j]) & 1;
  }
  scanf("%d", &n);
  printf("%d\n", n);
  for (int i = 0; i < n + 1; i++) printf("%d ", a[n][i]);
  printf("\n%d\n", n - 1);
  for (int i = 0; i < n; i++) printf("%d ", a[n - 1][i]);
}
