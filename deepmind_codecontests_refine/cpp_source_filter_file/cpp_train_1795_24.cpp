#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  n = 11;
  int niz[11];
  for (int i = 0; i < 11; i++) {
    cin >> niz[i];
  }
  for (int i = 10; i >= 0; i--) {
    double a = sqrt(abs(niz[i]));
    double b = pow(niz[i], 3) * 5;
    double result = a + b;
    if (result > 110)
      cout << "f(" << niz[i] << ") = MAGNA NIMIS!\n";
    else
      cout << "f(" << niz[i] << ") = " << setprecision(2) << fixed << result
           << endl;
  }
}
