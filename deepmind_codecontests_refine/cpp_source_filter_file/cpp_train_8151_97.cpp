#include <bits/stdc++.h>
using namespace std;
int n, k, l, c, d, p, nl, np, neto, litic = 0, salic = 0, cont = 0, limonic;
int main() {
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  neto = k * l;
  limonic = c * d;
  while (litic < neto && salic < p && cont < limonic) {
    litic = litic + nl;
    salic = salic + np;
    cont++;
  }
  cout << cont / n;
}
