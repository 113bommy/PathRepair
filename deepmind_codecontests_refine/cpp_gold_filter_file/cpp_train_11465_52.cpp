#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int d;
    cin >> d;
    double z, k, m;
    z = (pow(d, 2) - (4 * d));
    if (z < 0) {
      cout << "N\n";
      continue;
    } else {
      cout << "Y ";
      k = (d + (sqrt(z))) / 2;
      m = d - k;
      cout << setprecision(13) << k << " " << setprecision(13) << m << " "
           << endl;
    }
  }
}
