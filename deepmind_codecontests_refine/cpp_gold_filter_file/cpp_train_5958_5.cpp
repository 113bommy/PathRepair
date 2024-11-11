#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, t;
  cin >> t;
  for (i = 0; i < t; i++) {
    long long int n, g, b, sum = 0, count = 0, sum2 = 0, m, h;
    cin >> n >> g >> b;
    if (n % 2 == 0)
      m = n / 2;
    else
      m = n / 2 + 1;
    h = m / g;
    if (m % g == 0)
      count = count + h * g + (h - 1) * b;
    else
      count = count + h * (g + b) + m % g;
    if (count < n) count = n;
    if (n <= g)
      cout << n << endl;
    else
      cout << count << endl;
  }
}
