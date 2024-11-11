#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main() {
  int n, i, j, k, c, p = 0;
  cin >> n;
  k = n;
  n = n * n;
  for (i = 1; i <= n / 2; i++) {
    printf("%d %d\n", i, n - p);
    p++;
  }
  return 0;
}
