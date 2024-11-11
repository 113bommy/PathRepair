#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, a, b, rest, sol = 0, div;
  cin >> n >> k >> a >> b;
  if (k != 1)
    while (n > 1) {
      if (n >= k) {
        rest = n % k;
        sol += a * rest;
        n -= rest;
        div = n / k;
        sol += min((n - div) * a, b);
        n = div;
      } else
        sol += a * (n - 1), n = 1;
    }
  else
    sol = min(a, b) * (n - 1);
  cout << sol;
  return 0;
}
