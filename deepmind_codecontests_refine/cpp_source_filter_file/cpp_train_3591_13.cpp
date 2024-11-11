#include <bits/stdc++.h>
using namespace std;
long n, m;
int main() {
  scanf("%ld %ld\n", &n, &m);
  if (m == n == 1)
    printf("%ld", 1);
  else if ((m < n && n / 2 >= m) || m == 1)
    printf("%ld", m + 1);
  else
    printf("%ld", m - 1);
  return 0;
}
