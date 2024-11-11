#include <bits/stdc++.h>
using namespace std;
const int m = 1000000007;
long long power(long long x, long long y) {
  long long t = 1;
  for (; y; y >>= 1, x = x * x % m)
    if (y & 1) t = t * x % m;
  return t;
}
int main() {
  long long int i, n;
  cin >> n;
  long long int x = power(3, (3 * n));
  long long int y = power(7, n);
  cout << ((x - y + m) % m) << "\n";
}
