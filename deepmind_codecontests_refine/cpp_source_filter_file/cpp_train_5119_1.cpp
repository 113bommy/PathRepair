#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200], b[200];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  printf("0 ");
  b[1] = a[1];
  for (int i = 2; i <= n; ++i) {
    int t = m - a[i];
    sort(b + 1, b + i - 1);
    int j = 1;
    while (t >= b[j] && j < i) {
      t -= b[j];
      ++j;
    }
    printf("%d ", i - j);
    for (j = 1; j <= i; ++j) b[i] = a[i];
  }
  return 0;
}
