#include <bits/stdc++.h>
using namespace std;
long long b_power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long min_div(long long n) {
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return i;
    }
  }
  return n;
}
int is_prime(long long n) {
  if (n == 2) return 1;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long x, y, ans;
  cin >> x >> y;
  if ((x == 0 || x == 1) && y == 0) {
    cout << 0;
    return 0;
  }
  if (x == 1 && y == 1) {
    cout << 1;
    return 0;
  }
  if (x > 0 && ((y >= 0 && y <= x) || ((y < 0) && (abs(y) < x)))) {
    ans = 1 + ((x - 1) * 4);
    if (x == abs(y) + 1) ans--;
    cout << ans;
  } else if (y > 0 && ((x >= 0 && x <= y) || ((x < 0) && (abs(x) <= y)))) {
    ans = 2 + ((y - 1) * 4);
    if (x == y) ans--;
    cout << ans;
  } else if (x < 0 &&
             ((y >= 0 && y <= abs(x)) || ((y < 0) && (abs(y) < abs(x))))) {
    x = abs(x);
    ans = 3 + ((x - 1) * 4);
    if (x == y) ans--;
    cout << ans;
  } else {
    ans = 4 + ((abs(y) - 1) * 4);
    if (x == y) ans--;
    cout << ans;
  }
}
