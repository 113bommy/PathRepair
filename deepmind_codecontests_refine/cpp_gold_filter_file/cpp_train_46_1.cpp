#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[100100], b[100100], c[100100];
  scanf("%d", &n);
  for (i = 0; i <= n - 1; i++) scanf("%d", &a[i]);
  for (i = 0; i <= n - 2; i++) scanf("%d", &b[i]);
  for (i = 0; i <= n - 3; i++) scanf("%d", &c[i]);
  sort(a, a + n);
  sort(b, b + n - 1);
  sort(c, c + n - 2);
  b[n - 1] = c[n - 2] = 0;
  for (i = 0; i <= n - 1; i++) {
    if (a[i] != b[i]) break;
  }
  cout << a[i] << ' ';
  for (i = 0; i <= n - 2; i++) {
    if (b[i] != c[i]) break;
  }
  cout << b[i] << endl;
  return 0;
}
