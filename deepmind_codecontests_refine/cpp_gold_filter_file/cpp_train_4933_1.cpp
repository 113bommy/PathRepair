#include <bits/stdc++.h>
using namespace std;
long long int add(long long int a, long long int b,
                  long long int p = 1000000007) {
  a %= p;
  b %= p;
  return (a + b + p) % p;
}
long long int mul(long long int a, long long int b,
                  long long int p = 1000000007) {
  a %= p;
  b %= p;
  return (a * b + p) % p;
}
long long int power(long long int x, long long int n,
                    long long int p = 1000000007) {
  if (x == 0) return 0;
  if (n == 0 || x == 1) return 1LL;
  long long int r = (power(x, n / 2, p)) % p;
  if (n & 1)
    return mul(mul(r, r, p), x, p);
  else
    return mul(r, r, p);
}
int main() {
  long long int n, s, t, c = 0;
  cin >> n >> s >> t;
  long long int a[n + 1];
  for (long long int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (s == t) {
    cout << 0;
    return 0;
  }
  if (a[t] == t || a[s] == s) {
    cout << -1;
    return 0;
  }
  long long int in = a[s];
  s = a[s];
  c++;
  while (s != t) {
    s = a[s];
    if (s == in) {
      cout << -1;
      return 0;
    }
    c++;
  }
  cout << c;
}
