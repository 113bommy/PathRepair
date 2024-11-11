#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  int a[1001];
  int i, j;
  int check;
  int count;
  int ans = 0;
  for (i = 0; i <= m; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < m; i++) {
    if (a[i] <= a[m])
      check = a[m] - a[i];
    else
      check = a[i] - a[m];
    count = 0;
    while (check) {
      count += check & 1;
      check >>= 1;
    }
    if (count <= k) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
