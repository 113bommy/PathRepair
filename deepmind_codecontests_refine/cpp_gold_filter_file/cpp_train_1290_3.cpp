#include <bits/stdc++.h>
using namespace std;
long long gCd(long long a, long long b) {
  if (b == 0) return a;
  return gCd(b, a % b);
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = (res * i) % 1000000007;
  return res;
}
long long nCr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
int32_t main() {
  long long x, y, m;
  cin >> x >> y >> m;
  if (x >= m | y >= m) {
    cout << 0;
  } else if (x <= 0 & y <= 0) {
    cout << -1;
  } else {
    long long result = 0;
    if (x < y) {
      long long temp = (y - x) / y;
      result += temp;
      x += temp * y;
    } else if (y < x) {
      long long temp = (x - y) / x;
      result += temp;
      y += temp * x;
    }
    while (max(x, y) < m) {
      if (x > y) {
        y += x;
        result++;
      } else {
        x += y;
        result++;
      }
    }
    cout << result;
  }
  return 0;
}
