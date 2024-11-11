#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  m = n / 2;
  for (int i = 1; i < m; i++)
    printf("%d %d %d\n", i, i + 1,
           2 * m - (i - 1) - i - 2 + (i == m - 1 ? (n & 1) : 0));
  for (int i = 1; i <= m; i++) printf("%d %d %d\n", i, i + m, 1);
  if (n & 1) printf("%d %d %d\n", n - 1, n, 1);
  for (int i = m + 1; i < 2 * m; i++) printf("%d %d\n", i, i + 1);
  printf("%d %d\n", n - 2, n);
  return 0;
}
