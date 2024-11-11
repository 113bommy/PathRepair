#include <bits/stdc++.h>
using namespace std;
long long a[110000], b[110000], c[110000];
int main() {
  long long n, k;
  scanf("%lld %lld", &n, &k);
  for (long long i = 0; i < n; i++) scanf("%lld", &a[i]);
  sort(a, a + n);
  if (a[0] == a[n - 1]) {
    printf("0\n");
    return 0;
  }
  long long ans = 1, sum = 0;
  c[0] = a[0];
  for (long long i = 1; i < n; i++) {
    if (a[i] == c[sum])
      ans++;
    else {
      b[sum++] = ans;
      c[sum] = a[i];
      ans = 1;
    }
  }
  b[sum] = ans;
  long long i = 0, j = sum, x, y;
  while (k > 0 && i <= j) {
    x = c[i + 1] - c[i];
    y = c[j] - c[j - 1];
    if (b[i] * x > b[j] * y) {
      if (k >= b[j] * y) {
        k -= b[j] * y;
        j--;
        b[j] += b[j + 1];
      } else {
        long long h = k / b[j];
        c[j] -= h;
        break;
      }
    } else {
      if (k >= b[i] * x) {
        k -= b[i] * x;
        i++;
        b[i] += b[i - 1];
      } else {
        long long h = k / b[i];
        c[i] += h;
        break;
      }
    }
  }
  printf("%lld\n", c[j] - c[i]);
}
