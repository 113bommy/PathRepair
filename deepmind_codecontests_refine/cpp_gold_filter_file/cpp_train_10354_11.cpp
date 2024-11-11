#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
long long int gcd(long long int a, long long int b) {
  long long int c;
  while (a != 0) {
    c = a;
    a = b % a;
    b = c;
  }
  return b;
}
void seive() {
  int i, j;
  int MAX = 1000006;
  int isprime[1000006];
  isprime[0] = isprime[1] = 1;
  for (i = 4; i < MAX; i += 2) isprime[i] = 1;
  for (i = 3; i * i < MAX; i += 2) {
    if (!isprime[i]) {
      for (j = i * i; j < MAX; j += 2 * i) {
        isprime[j] = 1;
      }
    }
  }
}
int main() {
  long long int sum, val, ans = 0, n, i;
  sum = 0;
  scanf("%lld", &n);
  for (i = (int)0; i < (int)n; ++i) {
    scanf("%lld", &val);
    sum -= val;
    if (sum < 0) {
      ans -= sum;
      sum = 0;
    }
    if (i != n - 1) sum += val;
  }
  printf("%lld\n", ans);
  return 0;
}
