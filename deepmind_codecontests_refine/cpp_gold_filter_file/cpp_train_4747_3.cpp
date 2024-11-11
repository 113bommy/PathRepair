#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<long long> v;
int main() {
  scanf("%I64d%I64d", &n, &k);
  if (k == 1) {
    printf("%I64d", n);
    return 0;
  }
  if (k > 2 * sqrt(n)) {
    cout << -1;
    return 0;
  }
  if (k * (k + 1) / 2 > n) {
    printf("%d", -1);
    return 0;
  }
  for (int i = 1; i <= sqrt(n); i++)
    if (n % i == 0) {
      v.push_back(i);
      if (i * i != n) v.push_back(n / i);
    }
  sort(v.begin(), v.end());
  for (int i = v.size() - 1; i >= 0; i--) {
    long long p = v[i];
    if (k * (k + 1) / 2 <= n / p) {
      for (int it = 1; it < k; it++) printf("%I64d ", it * p);
      printf("%I64d", n - ((k - 1) * k / 2 * p));
      return 0;
    }
  }
  printf("%d", -1);
  return 0;
}
