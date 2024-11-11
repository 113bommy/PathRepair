#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int niz[n];
  for (int i = 0; i < n; i++) {
    niz[i] = i + 1;
  }
  while (m >= 0) {
    for (int j = 0; j < n; j++) {
      if (niz[j] <= m) {
        m -= niz[j];
      } else {
        cout << m << endl;
        m = -1;
        break;
      }
    }
  }
  return 0;
}
