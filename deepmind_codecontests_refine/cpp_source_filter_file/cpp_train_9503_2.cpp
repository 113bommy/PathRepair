#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[30];
  int n;
  scanf("%d", &n);
  a[0] = 1;
  for (int i = 1; i <= 20; i++) a[i] = a[i - 1] * i;
  long long ans = a[n] / a[n / 2] / a[n / 2];
  ans = ans * a[n / 2 - 1];
  ans = ans * a[n / 2 - 1];
  ans /= 2;
  printf("%lld\n", ans);
  return 0;
}
