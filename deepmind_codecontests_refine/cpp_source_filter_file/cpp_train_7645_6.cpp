#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i;
  cin >> n >> m;
  long double ans = 1.00 * n;
  cout.precision(15);
  if (n == 1) {
    cout << 1.00 * n / 2;
    return 0;
  }
  for (i = n - 1; i >= 1; i--) {
    long double temp = 1.00 * i / n;
    ans -= pow(temp, m);
  }
  cout << ans;
}
