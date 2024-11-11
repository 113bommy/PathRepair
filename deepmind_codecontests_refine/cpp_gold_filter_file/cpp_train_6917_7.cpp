#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, a[N], b[N], t[N];
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d\n", &a[i], &b[i]);
    for (int j = a[i]; j <= b[i]; j++) t[j]++;
  }
  for (int i = 1; i <= n; i++)
    if (t[i] != 1) {
      printf("%d %d\n", i, t[i]);
      return 0;
    }
  printf("OK\n");
  return 0;
}
