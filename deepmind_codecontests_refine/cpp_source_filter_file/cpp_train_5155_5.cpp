#include <bits/stdc++.h>
using namespace std;
int n, nrli[200005], min1, prov, fin, val1, parc, cons[200005];
int main() {
  cin >> n;
  cin >> nrli[0];
  min1 = nrli[0];
  for (int i = 1; i < n; i++) {
    cin >> nrli[i];
    if (nrli[i] < min1) min1 = nrli[i];
  }
  for (int i = 0; i < n; i++) {
    nrli[i] = nrli[i] - min1;
  }
  parc = n * min1;
  for (int i = 0; i <= n * 2; i++) {
    if (nrli[i % n] != 0)
      prov++;
    else {
      if (prov > fin) fin = prov;
      prov = 0;
    }
  }
  cout << parc + fin;
  return 0;
}
