#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000009;
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  long long int p = power(x, y / 2) % mod;
  p = (p * p) % mod;
  return (y % 2 == 0) ? p : (x * p) % mod;
}
int main() {
  long long int n, a, b, k, arr[100001], i, sum = 0, temp, res;
  char t[100002];
  scanf("%lld %lld %lld %lld", &n, &a, &b, &k);
  scanf("%s", t);
  for (i = 0; i < k; i++) {
    if (t[i] == '+')
      arr[i] = 1;
    else
      arr[i] = -1;
  }
  for (i = 0; i < k; i++) {
    sum += arr[i] * ((power(a, n - i) * power(b, i)) % mod);
    sum = sum % mod;
  }
  temp = (power(a, k * (mod - 2)) * power(b, k)) % mod;
  if (temp == 1)
    res = (sum * (n + 1) / k) % mod;
  else {
    res = (sum *
           (power(temp - 1, mod - 2) * (power(temp, (n + 1) / k) - 1) % mod)) %
          mod;
  }
  if (res < 0) res += mod;
  printf("%lld", res);
  return 0;
}
