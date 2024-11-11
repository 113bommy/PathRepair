#include <bits/stdc++.h>
using namespace std;
long long cubic_root(long long x) {
  long long l = 0, r = 1000005;
  while (l < r) {
    long long m = (l + r) / 2;
    long long f = m * m * m;
    if (f > x)
      r = m - 1;
    else if (f == x)
      return m;
    else
      l = m + 1;
  }
  return l;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    long long x = cubic_root(a * b);
    if (x * x * x != a * b)
      cout << "NO\n";
    else if (a % x == 0 && b % x == 0)
      cout << "YES\n";
    else
      cout << "no\n";
  }
}
