#include <bits/stdc++.h>
using namespace std;
int n, k, suma, sumb, sumc, a, b;
int main() {
  ios::sync_with_stdio(false);
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    suma += a / 4, sumb += a % 4 / 2, sumc += a % 2;
  }
  a = k, b = k * 2;
  if (a >= suma) {
    a -= suma, suma = 0;
    cout << ((sumb <= a + b || (sumb - a - b) * 2 + sumc <= a * 2 + b) &&
                     sumb + sumc <= a * 2 + b
                 ? "YES"
                 : "NO")
         << endl;
  } else {
    suma -= a, a = 0;
    cout << (suma * 2 + sumb + sumc > b ? "NO" : "YES") << endl;
  }
  return 0;
}
