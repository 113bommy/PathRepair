#include <bits/stdc++.h>
using namespace std;
const int N = 233;
int a[N][N];
int main() {
  ios::sync_with_stdio(false);
  int m, n, q, p, x, y, b;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> a[i][0];
  p = a[0][0];
  for (int i = 0; i < m; ++i) cin >> a[0][i];
  q = a[0][0];
  x = y = b = 0;
  for (int i = 1; i < n; ++i) x ^= a[i][0];
  for (int i = 1; i < m; ++i) y ^= a[0][i];
  if ((y ^ p) != (x ^ q)) {
    printf("NO\n");
    return 0;
  } else {
    b = y ^ p;
    a[0][0] = b;
    printf("YES\n");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) printf("%d ", a[i][j]);
      printf("\n");
    }
  }
  return 0;
}
