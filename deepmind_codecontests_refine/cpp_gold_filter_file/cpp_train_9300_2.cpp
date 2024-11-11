#include <bits/stdc++.h>
using namespace std;
long long n, x, P(1000000007LL);
long long pow(long long x, long long y) {
  long long ret(1);
  for (; y; y >>= 1) {
    if (y & 1) ret = ret * x % P;
    x = x * x % P;
  }
  return ret;
}
int main() {
  cin >> n;
  x = pow(2, n);
  x = (x * (x + 1) / 2) % P;
  cout << x << endl;
  return 0;
}
