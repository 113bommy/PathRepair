#include <bits/stdc++.h>
using namespace std;
long long check(long long a) {
  long long f = 0;
  for (long long i = 2; i * i <= a; i++)
    if (a % i == 0) {
      f = 1;
      break;
    }
  return f;
}
int32_t main() {
  long long n;
  cin >> n;
  for (long long i = 2;; i++) {
    long long a = i;
    long long b = i + n;
    if (check(a) && check(b)) return cout << a << " " << b << '\n', 0;
  }
}
