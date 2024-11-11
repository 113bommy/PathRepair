#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    double a, b;
    if (n > 0 && n < 4)
      cout << "N\n";
    else {
      cout << "Y ";
      a = (n + sqrt(n * n - 4 * n)) / 2;
      b = n - a;
      cout << fixed << setprecision(9) << a << " " << b << "\n";
    }
  }
}
