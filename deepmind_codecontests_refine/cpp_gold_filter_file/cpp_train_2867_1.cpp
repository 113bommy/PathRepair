#include <bits/stdc++.h>
using namespace std;
int v[1001], u[1001], n, a, b, c, d, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  scanf("%d%d%d%d%d%d", &n, &k, &a, &b, &c, &d);
  if (n == 5) {
    if (k <= 5) {
      printf("-1");
      return 0;
    }
    int e = 15 - (a + b + c + d);
    printf("%d %d %d %d %d\n%d %d %d %d %d", a, d, e, c, b, c, b, e, a, d);
    return 0;
  }
  if (n == 4 || k <= n) {
    printf("-1");
    return 0;
  }
  int e = 1;
  while (e == a || e == b || e == c || e == d) e++;
  v[1] = a;
  v[2] = c;
  v[3] = e;
  v[4] = d;
  int cnt = 4;
  for (int i = 1; i <= n; ++i) {
    if (i - a && i - b && i - c && i - d && i - e) v[++cnt] = i;
  }
  v[n] = b;
  for (int i = 1; i <= n; ++i) {
    printf("%d ", v[i]);
  }
  u[1] = c;
  u[2] = a;
  u[3] = e;
  u[4] = b;
  cnt = 4;
  for (int i = n - 1; i >= 4; --i) {
    u[++cnt] = v[i];
  }
  printf("\n");
  for (int i = 1; i <= n; ++i) {
    printf("%d ", u[i]);
  }
  return 0;
}
