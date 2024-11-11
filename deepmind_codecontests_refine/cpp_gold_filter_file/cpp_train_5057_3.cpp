#include <bits/stdc++.h>
using namespace std;
long long int n, k, i;
int main(void) {
  scanf("%I64d %I64d", &n, &k);
  float lim = sqrt(n);
  std::vector<long long int> v;
  for (i = 1; i <= lim; ++i) {
    if (n % i == 0) v.push_back(i);
  }
  long long int q = v.size();
  if (n == 1) {
    switch (k) {
      case 1:
        cout << 1;
        break;
      default:
        cout << -1;
        break;
    }
    return 0;
  }
  if (q == 1) {
    switch (k) {
      case 1:
        printf("1");
        break;
      case 2:
        printf("%I64d", n);
        break;
      default:
        printf("-1");
        break;
    }
    return 0;
  }
  if (v[q - 1] * v[q - 1] == n) {
    if (k <= q)
      printf("%I64d", v[k - 1]);
    else if (k < (2 * q) && v[q - 1 - k % q])
      printf("%I64d", n / v[q - 1 - k % q]);
    else
      printf("-1");
  } else {
    if (k <= q)
      printf("%I64d", v[k - 1]);
    else if (k < (2 * q) && v[q - k % q])
      printf("%I64d", n / v[q - k % q]);
    else if (k == 2 * q)
      printf("%I64d", n);
    else
      printf("-1");
  }
  return 0;
}
