#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const long long N = 1e5 + 5;
int main() {
  long long n, i, j, k, s = 0, fl = 1;
  cin >> n;
  s = n + 1;
  while (n > 1 && fl) {
    long long x = 0;
    for (i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        s += n / i;
        n /= i;
        x = 1;
      }
    }
    if (!x) fl = 0;
  }
  cout << s;
}
