#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a;
  scanf("%d%d", &n, &m);
  if (n == 1)
    a == 1;
  else if (m == 1)
    a = 2;
  else if (m == n)
    a = n - 1;
  else if (m - 1 < n - m)
    a = m + 1;
  else
    a = m - 1;
  printf("%d", a);
  return 0;
}
