#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000010];
int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) scanf("%d", &x), ++a[x];
  for (int i = 0; i <= 2000000; ++i) a[i + 1] += a[i] / 2, n -= a[i] / 2;
  printf("%d\n", n);
  return 0;
}
