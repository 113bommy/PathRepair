#include <bits/stdc++.h>
using namespace std;
long long a[1000000], ans;
long long rev(long long n) {
  long long c = 0;
  while (n > 0) {
    c = c * 10 + n % 10;
    n /= 10;
  }
  return c;
}
int main() {
  long long a, b;
  cin >> a >> b;
  b = rev(b);
  cout << b + a;
}
