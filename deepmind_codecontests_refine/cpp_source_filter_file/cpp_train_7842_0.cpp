#include <bits/stdc++.h>
using namespace std;
int main() {
  long double k, b, n, t;
  cin >> k >> b >> n >> t;
  long double m = 1;
  while (n > 0 && m <= (t - b) / k) m = m * k + b, n--;
  cout << n;
  return 0;
}
