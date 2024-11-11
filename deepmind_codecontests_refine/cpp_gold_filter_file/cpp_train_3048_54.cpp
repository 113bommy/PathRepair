#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000000 + 7;
long long N = 100107;
long long binpow(long long x, long long y) {
  if (y == 1)
    return x;
  else if (y % 2 == 0) {
    long long w = binpow(x, y / 2);
    return w * w;
  } else
    return x * binpow(x, y - 1);
}
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    long long x = 1;
    cout << (a ^ b) << "\n";
  }
}
