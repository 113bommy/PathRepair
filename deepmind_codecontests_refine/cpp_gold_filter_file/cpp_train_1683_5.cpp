#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, d = 9, digc = 1, c = 1;
  cin >> n;
  while (n > c * d) {
    n -= c * d;
    c++;
    d *= 10;
    digc *= 10;
  }
  digc += (n - 1) / c;
  cout << to_string(digc)[int((n - 1) % c)];
  return 0;
}
