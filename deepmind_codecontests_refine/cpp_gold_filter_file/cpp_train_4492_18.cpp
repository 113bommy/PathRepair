#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y, p, q;
  scanf("%lld %lld %lld", &n, &x, &y);
  p = x - (n - 1);
  q = sqrt(p);
  if (q * q != p) q = q + 1;
  if (p <= 0) q = 1;
  if (q + (n - 1) <= y) {
    cout << q << endl;
    for (int i = 0; i < n - 1; i++) printf("1\n");
  } else
    printf("-1\n");
  return 0;
}
