#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e9;
const long double PI = 3.14159265358979323846;
const long long INF = 1e6 - 1;
long long prime1(long long n) {
  bool ans = false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      ans = true;
      break;
    }
  }
  if (ans == 0) {
    return 1;
  } else {
    return 0;
  }
}
long long Catalan(long long n) {
  long long i, sum;
  if (n <= 0) {
    return 1;
  }
  sum = 0;
  for (i = 0; i < n; i++) {
    sum += Catalan(i) * Catalan((n - 1) - i);
  }
  return sum;
}
using namespace std;
int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  if (2 * c >= n && n >= c && b > n && c > n)
    cout << a * 2 << " " << b * 2 << " " << n;
  else if (2 * n >= c && c >= n)
    cout << a * 2 << " " << b * 2 << " " << c;
  else
    cout << -1;
}
