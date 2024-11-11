#include <bits/stdc++.h>
using namespace std;
long long int n, k, m;
long long int a[100005];
long long int b[100005];
long long int in = 1;
int main() {
  scanf("%lld", &n);
  scanf("%lld", &k);
  scanf("%lld", &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long int i = 1, j = 1;
  long long int ans = n * m;
  while (i <= n && j <= n) {
    while (j <= n && a[i] == a[j]) j++;
    ans -= (((j - i) / k) * k) * m;
    if ((j - i) % k != 0) {
      if (a[in - 1] == a[i]) {
        ans -= (((b[in - 1] + ((j - i) % k)) / k) * k) * m;
        b[in - 1] = (b[in - 1] + ((j - i) % k)) % k;
        if (b[in - 1] == 0) in--;
      } else {
        b[in] = (j - i) % k;
        a[in] = a[i];
        in++;
      }
    }
    i = j;
  }
  i = 1, j = in - 1;
  while (i <= n && j >= 1) {
    if (i > j) {
      if (a[i] == a[j]) {
        ans -= (((b[i] + b[j]) / k) * k);
        if ((b[i] + b[j]) % k == 0) {
          i++, j--;
        } else
          break;
      } else
        break;
      continue;
    }
    if (a[i] == a[j]) {
      if (j == i + 1) {
        ans -= (((b[i] + b[j]) * m) / k) * k;
        if (((b[i] + b[j]) * m) % k == 0) {
          i++, j--;
        } else
          break;
        continue;
      }
      if (i != j) {
        ans -= (((b[i] + b[j]) / k) * k) * (m - 1);
        if ((b[i] + b[j]) % k == 0) {
          i++, j--;
        } else
          break;
      } else {
        ans -= (((b[i] * m) / k) * k);
        if ((m * b[i]) % k == 0)
          i++, j--;
        else
          break;
      }
    } else
      break;
  }
  printf("%lld\n", ans);
  return 0;
}
