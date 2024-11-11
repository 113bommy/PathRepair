#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, k, nb = 0, i, bal = 0;
  cin >> n;
  cin >> h;
  cin >> k;
  int T[n];
  for (i = 0; i < n; i++) {
    cin >> T[i];
    if (bal + T[i] <= h)
      bal += T[i];
    else {
      nb++;
      bal = T[i];
    }
    nb += bal / k;
    bal = bal % k;
    if ((i == n - 1) && (bal != 0)) nb++;
  }
  cout << nb;
  return 0;
}
