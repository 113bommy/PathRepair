#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;
  long long r1 = n / a, r2 = 0;
  if (n >= b) {
    n -= b;
    r2 = n / (b - c) + 1;
    n %= (b - c);
    n += c;
    r2 += n / a;
  }
  cout << max(r1, r2);
  return 0;
}
