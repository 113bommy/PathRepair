#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
int a[N], b[N];
void solve() {
  int n, m = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0, j; i < n; i = j) {
    for (j = i; j < n && a[i] == a[j]; j++)
      ;
    b[m++] = j - i;
  }
  int x, y, z, t, i, j;
  x = b[0];
  y = z = t = 0;
  for (i = 1; i < m && y <= x; y += b[i], i++)
    ;
  for (i = 1; i < m && z <= x; z += b[i], i++)
    ;
  j = i;
  for (; i < m; t += b[i], i++)
    ;
  if (x >= y || x >= z || x + y + z > n - x - y - z) {
    puts("0 0 0");
    return;
  }
  while (x + y + z + b[j] <= n - x - y - z - b[j]) {
    z += b[j];
    j++;
  }
  cout << x << ' ' << y << ' ' << z << endl;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
