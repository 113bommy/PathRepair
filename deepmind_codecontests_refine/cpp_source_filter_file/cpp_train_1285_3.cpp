#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k, b, n, t, x = 1;
  cin >> k >> b >> n >> t;
  while (x < t) x = k * x + b, --n;
  n = max(0LL, n);
  cout << n << endl;
  return 0;
}
