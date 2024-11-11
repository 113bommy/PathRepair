#include <bits/stdc++.h>
using namespace std;
int n, k, suma[100005], sumb[100005];
int main() {
  char ch;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> ch;
    suma[i] = suma[i - 1] + (ch == 'a');
    sumb[i] = sumb[i - 1] + (ch == 'b');
  }
  int L = 1, R = n, mij, poz = 0, x, y, p;
  while (L <= R) {
    mij = (L + R) / 2;
    bool ok = false;
    for (int i = mij; i <= n; i++) {
      x = suma[mij] - suma[i - mij];
      y = sumb[mij] - sumb[i - mij];
      p = min(x, y);
      ok |= (p <= k);
    }
    if (ok)
      poz = mij, L = mij + 1;
    else
      R = mij - 1;
  }
  cout << poz << "\n";
  return 0;
}
