#include <bits/stdc++.h>
using namespace std;
int i, j, k, m, n;
int main() {
  cin >> n;
  m = n / 2;
  k = 1;
  if (n == 5) {
    printf("1 3 1\n1 2 3\n2 4 1\n4 5 2\n3 4\n3 5\n");
    return 0;
  }
  for (i = 1; i <= m; i++) printf("%d %d 1\n", i, i + m);
  for (i = m + 1; i < n; i++, k += 2) printf("%d %d %d\n", i, i + 1, k);
  for (i = 1; i < m; i++) printf("%d %d\n", i, i + 1);
  printf("1 3\n");
  return 0;
}
