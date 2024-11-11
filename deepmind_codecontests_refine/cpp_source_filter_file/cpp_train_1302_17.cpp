#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int fastpowmod(long long int b, long long int e, long long int m) {
  if (e == 0) return 1;
  if (e == 1) return b;
  long long int aux = fastpowmod((b * b) % m, e / 2, m) % m;
  if (e % 2) return (b * aux) % m;
  return aux;
}
int main() {
  long long int p, k;
  cin >> p >> k;
  if (k == 0)
    cout << fastpowmod(p - 1, p - 1, mod) << endl;
  else if (k == 1)
    cout << fastpowmod(p, p, mod) << endl;
  else {
    long long int orden = 1;
    while (fastpowmod(k, orden, p) != 1) ++orden;
    cout << fastpowmod(p, (p - 1) / orden, mod) << endl;
  }
}
