#include <bits/stdc++.h>
using namespace std;
long long __gcd(long long a, long long b) {
  long long r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long a[101];
    for (int i = 0; i < n; i++) cin >> a[i];
    long long x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0)
        x = __gcd(x, a[i]);
      else
        y = __gcd(y, a[i]);
    }
    int sum1 = 1, sum2 = 1;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0 && a[i] % y == 0) sum1 = 0;
      if (i % 2 == 1 && a[i] % x == 0) sum2 = 0;
    }
    if (sum2)
      cout << x << endl;
    else if (sum1)
      cout << y << endl;
    else
      cout << 0 << endl;
  }
}
