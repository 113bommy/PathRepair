#include <bits/stdc++.h>
using namespace std;
long long int i, n, m, v, sum, j, a, f;
int main() {
  scanf("%ld %ld %ld", &n, &m, &v);
  if (m == 0 || m < n - 1) {
    printf("-1\n");
    return 0;
  }
  sum = (n * n) - ((n * (1 + n)) / 2) - (n - 2);
  if (m > sum) {
    printf("-1\n");
    return 0;
  }
  a = 0;
  for (j = 1; j <= n; j++) {
    if (j != v) {
      cout << j << " " << v << endl;
      a++;
    }
    if (a == m) return 0;
  }
  f = 0;
  if (n == v) f = 1;
  for (i = 1; i < n - f; i++) {
    for (j = i + 1; j < n - f; j++) {
      if (i != v && j != v) {
        cout << i << " " << j << endl;
        a++;
      }
      if (a == m) return 0;
    }
  }
  return 0;
}
