#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  long long n, m, x, y, z;
  scanf("%lld", &n), scanf("%lld", &m);
  for (long long i = 0; i < m; i++) {
    scanf("%lld", &x), scanf("%lld", &y), scanf("%lld", &z);
    if (a[x] == 1)
      a[y] = 2, a[z] = 3;
    else if (a[x] == 2)
      a[y] = 1, a[z] = 3;
    else if (a[x] == 3)
      a[y] = 1, a[z] = 2;
    else if (a[y] == 1)
      a[x] = 2, a[z] = 3;
    else if (a[y] == 2)
      a[x] = 1, a[z] = 3;
    else if (a[y] == 3)
      a[x] = 1, a[z] = 2;
    else if (a[z] == 1)
      a[x] = 3, a[y] = 2;
    else if (a[z] == 2)
      a[x] = 1, a[y] = 3;
    else if (a[z] == 3)
      a[x] = 1, a[y] = 2;
    else
      a[x] = 1, a[y] = 2, a[z] = 3;
  }
  for (long long i = 1; i < n + 1; i++) printf("%lld ", a[i]);
  return 0;
}
