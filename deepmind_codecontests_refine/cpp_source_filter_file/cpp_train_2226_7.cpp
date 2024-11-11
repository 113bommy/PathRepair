#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k;
const int a[] = {1, 2, 64, 625, 7776, 117649, 2097152};
inline long long power(int x, int y) {
  long long tot = 1;
  for (int i = 1; i <= y; i++) tot = tot * x % mod;
  return tot;
}
int main() {
  scanf("%d%d", &n, &k);
  printf("%I64d\n", power(n - k, n - k) * a[k - 1] % mod);
  return 0;
}
