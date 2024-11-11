#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int cont = 0;
    bool tr = false;
    while (n != 1 && !tr) {
      if (n % 5 != 0 && n % 3 != 0 && n % 2 != 0) {
        cout << 0 << endl;
        tr = true;
      }
      if (n % 2 == 0) {
        n /= 2;
        cont++;
      }
      if (n % 3 == 0) {
        n = 2 * n / 3;
        cont++;
      }
      if (n % 5 == 0) {
        n = 4 * n / 5;
        cont++;
      }
    }
    if (!tr) cout << cont << endl;
  }
  return 0;
}
