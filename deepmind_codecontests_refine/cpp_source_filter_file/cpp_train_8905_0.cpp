#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  unsigned long long r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
int main() {
  unsigned long long sc = 2, n, ans, inf = 10e18;
  cin >> n;
  for (unsigned long long i = 1; i <= n; i++) {
    unsigned long long temp = i / gcd(i, i + 1) * (i + 1);
    if (sc > temp) temp = (sc / temp + 1) * temp;
    ans = (temp * temp - sc) / i;
    sc = temp;
    cout << ans << endl;
  }
  return 0;
}
