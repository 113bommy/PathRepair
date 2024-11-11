#include <bits/stdc++.h>
using namespace std;
long long s(long long x) {
  long long r = 0;
  while (x) {
    r += x % 10;
    x /= 10;
  }
  return r;
}
int main() {
  long long n;
  cin >> n;
  for (long long i = sqrt(n); i >= sqrt(n) - 1000000; i--) {
    if (n == powl(i, 2) + s(i) * i) return cout << i, 0;
  }
  cout << -1;
  return 0;
}
