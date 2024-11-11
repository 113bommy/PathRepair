#include <bits/stdc++.h>
using namespace std;
long long int n, m, i, j, k, l, t;
int main() {
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld %lld", &n, &m);
    if (n < m) swap(n, m);
    k = 0;
    while (n > m && n % 2 == 0) {
      n /= 2;
      k++;
    }
    l = k / 3;
    i = k % 3;
    if (i > 0) l++;
    if (n != m)
      printf("-1\n");
    else
      printf("%lld\n", l);
  }
}
