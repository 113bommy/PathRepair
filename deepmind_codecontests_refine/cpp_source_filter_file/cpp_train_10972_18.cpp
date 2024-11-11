#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:258435456");
using namespace std;
struct Point {
  long double x, y;
};
int sign(long double t) {
  if (t >= 0)
    return 1;
  else
    return -1;
}
long long mul(long long x, int y) {
  if (y == 0)
    return 1;
  else if (y & 1)
    return x * mul(x, y - 1) % 1000000009;
  else {
    long long tmp = mul(x, y / 2);
    return tmp * tmp % 1000000009;
  }
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long t = n - n / k;
  if (t >= m)
    cout << m;
  else {
    long long sum = 0;
    long long l = m - t;
    sum = (mul(2, l) - 1 + 1000000009) * k % 1000000009;
    if (m - l * k >= 0) sum += m - l * k;
    cout << sum % 1000000009;
  }
  return 0;
}
