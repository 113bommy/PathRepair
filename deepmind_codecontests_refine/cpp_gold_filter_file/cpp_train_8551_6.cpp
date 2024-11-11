#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, unsigned long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) {
      res = res * x;
    }
    y = y >> 1;
    x = x * x;
  }
  return res;
}
long long int powermod(long long int x, unsigned long long int y,
                       long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) {
      res = (res * x) % p;
    }
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int calc(long long int a, long long int b, long long int g) {
  long long int wh = (b + g - 1) / g;
  long long int k = wh * g - b;
  return ((a + k) * (b + k) / g);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  if (a < b) swap(a, b);
  if (a == b) {
    cout << 0 << "\n";
    return 0;
  }
  long long int g = llabs(a - b), ans = 2e18, fans = 0;
  for (long long int i = 1; i * i <= g; i++) {
    if (g % i) continue;
    long long int f1 = i, f2 = g / i;
    long long int o1 = calc(a, b, f1);
    if (o1 < ans) {
      ans = o1;
      fans = f1;
    }
    long long int o2 = calc(a, b, f2);
    if (o2 < ans) {
      ans = o2;
      fans = f2;
    }
  }
  long long int wh = (b + fans - 1) / fans;
  long long int k = wh * fans - b;
  cout << k << "\n";
  return 0;
}
