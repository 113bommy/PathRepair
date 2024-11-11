#include <bits/stdc++.h>
using namespace std;
long long n, a, b;
long long C(int n, int x) {
  if (x > n) return 0ll;
  long long tmp = 1ll;
  for (int i = (n); i >= (n - x + 1); i--) {
    tmp *= (long long)i;
  }
  for (int i = (1); i <= (x); i++) tmp /= (long long)(i);
  return tmp;
}
int main() {
  scanf("%I64d", &n);
  a = C(n, 1) + C(n, 2) * 2ll + C(n, 3);
  b = C(n, 1) + 4ll * C(n, 2) + C(n, 3) * 6ll + C(n, 4) * 4ll + C(n, 5);
  printf("%I64d\n", a * b);
  return 0;
}
