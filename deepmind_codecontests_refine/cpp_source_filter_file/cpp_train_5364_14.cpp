#include <bits/stdc++.h>
long long int sum;
long long int recursion(long long int t, long long int p) {
  if (t == 0) return 0;
  long long int a;
  char str[8];
  scanf("%s", str);
  if (str[4] == 'p') {
    a = 2 * recursion(t - 1, p) + 1;
    float q = a / 2.0;
    sum += q * p;
  } else {
    a = 2 * recursion(t - 1, p);
    sum += (a / 2) * p;
  }
  return a;
}
int main() {
  long long int n, p, t;
  scanf("%lld%lld", &n, &p);
  t = recursion(n, p);
  printf("%lld", sum);
  return 0;
}
