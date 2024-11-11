#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000007;
long long int power(long long int x, long long int n) {
  long long int r = 1;
  x = x % m;
  while (n > 0) {
    if (n & 1) r = (r * x) % m;
    n /= 2;
    x = (x * x) % m;
  }
  return r;
}
int main(void) {
  long long int i, c, k, n, s;
  s = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  c = power(2, n - 1);
  k = 1;
  for (i = 0; i < (n / 2); i++) {
    c = power(2, n - i - 1);
    s += ((c - k + m) % m * (a[n - i - 1] - a[i]) % m) % m;
    k = ((k % m) * (2 % m)) % m;
  }
  cout << s;
  return 0;
}
