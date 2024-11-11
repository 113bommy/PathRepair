#include <bits/stdc++.h>
using namespace std;
long n, a[100000];
long t1, t2, t3, res;
int main() {
  scanf("%ld", &n);
  for (long i = 1; i <= n; i++) scanf("%ld", &a[i]);
  for (long i = 1; i <= n; i++)
    if (a[i] % 3 == 0)
      t1++;
    else if (a[i] % 3 == 1)
      t2++;
    else
      t3++;
  res = t1 + min(t2, t3);
  printf("%ld\n", res);
}
