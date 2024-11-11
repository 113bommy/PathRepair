#include <bits/stdc++.h>
using namespace std;
int main() {
  int nb[11];
  for (int i = 0; i < 11; i++) {
    cin >> nb[i];
  }
  cout << fixed << setprecision(2);
  for (int i = 0; i < 11; i++) {
    double res =
        5 * nb[10 - i] * nb[10 - i] * nb[10 - i] + sqrt(abs(nb[10 - i]));
    if (res > 900)
      cout << "f(" << nb[10 - i] << ") = MAGNA NIMIS!\n";
    else
      cout << "f(" << nb[10 - i] << ") = " << res << "\n";
  }
  return 0;
}
