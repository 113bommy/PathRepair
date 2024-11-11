#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    long long e = (a / c) + ((a % c) != 0);
    long long f = (b / d) + ((b % d) != 0);
    if (e + f > k)
      cout << "-1\n";
    else {
      if (e < f)
        cout << e << " " << k - e << "\n";
      else
        cout << k - f << " " << f << "\n";
    }
  }
}
