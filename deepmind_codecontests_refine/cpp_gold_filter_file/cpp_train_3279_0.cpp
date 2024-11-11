#include <bits/stdc++.h>
using namespace std;
const int nmax = 100000;
bool u[nmax + 1];
int p[nmax + 1];
int main() {
  int n, nr1 = 0, nr2 = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (p[i] == i) {
      nr1 = i;
    }
    if (p[p[i]] == i) {
      nr2 = i;
    }
  }
  if (nr1 != 0) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      if (i != nr1) {
        cout << nr1 << " " << i << "\n";
      }
    }
  } else if (nr2 != 0) {
    for (int i = 1; i <= n; ++i) {
      if (i != nr2 && i != p[nr2]) {
        int aux = 0;
        for (int pos = i; u[pos] == 0; pos = p[pos]) {
          u[pos] = 1;
          ++aux;
        }
        if (aux % 2 == 1) {
          cout << "NO\n";
          return 0;
        }
      }
    }
    cout << "YES\n" << nr2 << " " << p[nr2] << "\n";
    for (int i = 1; i <= n; ++i) u[i] = 0;
    for (int i = 1; i <= n; ++i) {
      if (i != nr2 && i != p[nr2]) {
        for (int pos = i, aux = 1; u[pos] == 0; pos = p[pos], ++aux) {
          u[pos] = 1;
          if (aux % 2 == 1) {
            cout << nr2 << " " << pos << "\n";
          } else {
            cout << p[nr2] << " " << pos << "\n";
          }
        }
      }
    }
  } else {
    cout << "NO\n";
  }
  return 0;
}
