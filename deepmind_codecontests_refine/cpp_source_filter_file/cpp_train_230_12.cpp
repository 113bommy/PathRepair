#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << setprecision(15)
         << (double)cos(1.57079632679489661923 / (2 * n)) /
                tan(1.57079632679489661923 / n)
         << endl;
  }
  return 0;
}
