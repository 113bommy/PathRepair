#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, count;
  int m, n, a[51];
  cin >> m >> n;
  for (i = 0; i < m; i++) cin >> a[i];
  sort(a, a + m);
  if (n > a[m - 1])
    printf("-1\n");
  else
    printf("%d %d\n", a[m - n], a[m - n]);
  return 0;
}
