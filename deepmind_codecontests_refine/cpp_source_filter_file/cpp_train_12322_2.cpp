#include <bits/stdc++.h>
using namespace std;
long long sum(long long x) {
  long long m = 0;
  while (x >= 1) {
    m += x % 10;
    x /= 10;
  }
  return m;
}
int main() {
  long long n, i;
  cin >> n;
  if (sqrt(n) - 1000 > 1) {
    i = sqrt(n) - 1000;
  }
  for (i; i <= sqrt(n); i++) {
    if (i * i + sum(i) * i - n == 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
