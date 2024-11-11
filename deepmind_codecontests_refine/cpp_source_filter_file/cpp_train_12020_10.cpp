#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b, sum = 0;
  cin >> n >> m >> a >> b;
  double t = m / b;
  if (t < a) {
    int p = n / m;
    int q;
    if (n % m == 0)
      q = 0;
    else
      q = 1;
    sum = min(p * b + (n % m) * a, n / m * b + q * b);
  } else
    sum = n * a;
  cout << sum;
  return 0;
}
