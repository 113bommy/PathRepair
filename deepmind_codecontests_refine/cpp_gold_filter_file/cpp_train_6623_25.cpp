#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int fact[2 * 100005];
long long int func() {
  fact[0] = fact[1] = 1;
  for (long long int i = 2; i < 200001; i++) {
    fact[i] = (fact[i - 1] * i) % 1000000007;
  }
}
long long int arr[100005];
int main() {
  long long int n, k, x;
  scanf("%lld", &n);
  scanf("%lld", &k);
  scanf("%lld", &x);
  for (long long int i = 0; i < n; i++) {
    scanf("%lld", &arr[i]);
  }
  sort(arr, arr + n);
  reverse(arr, arr + n);
  long long int j = k, ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (j) {
      ans += x;
      j--;
    } else {
      ans += arr[i];
    }
  }
  printf("%lld\n", ans);
}
