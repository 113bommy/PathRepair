#include <bits/stdc++.h>
using namespace std;
void IO() {}
int main() {
  int cases = 1, t = 0;
  long long n, m, k, x, y, d;
  while (cases--) {
    scanf("%lld %lld", &n, &k);
    long long a[n];
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
    }
    sort(a, a + n);
    x = a[0];
    printf("%lld\n", a[0]);
    k--;
    for (int i = 1; i < n && k > 0; i++) {
      long long y = a[i] - x;
      if (y > 0) {
        printf("%lld\n", y);
        x += a[i];
        k--;
      }
    }
    while (k--) printf("0\n");
  }
  return 0;
}
