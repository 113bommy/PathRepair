#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010];
int c = 0, n, m;
void f(int x, int y) {
  if (x > n || y > n || c == m) return;
  a[c] = x;
  b[c] = y;
  ++c;
  f(x, x + y);
  f(y, x + y);
}
int main() {
  scanf("%d%d", &n, &m);
  if (m < n - 1) {
    printf("Impossible\n");
    return 0;
  }
  f(2, 1);
  if (c < m)
    printf("Impossible\n");
  else {
    printf("Possible\n");
    for (int i = 0; i < m; ++i) printf("%d %d\n", a[i], b[i]);
  }
  return 0;
}
