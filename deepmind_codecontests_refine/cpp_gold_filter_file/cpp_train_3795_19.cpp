#include <bits/stdc++.h>
using namespace std;
const long long max1 = 101;
int main() {
  char a[51][101];
  bool debug = false;
  int otkl = 0;
  if (debug) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  int n;
  cin >> n;
  for (size_t i = 0; i < (n + 1) / 2; i++) {
    for (size_t j = 0; j < n; j++) {
      if ((j <= ((n - 1) / 2) + otkl) && (j >= ((n - 1) / 2) - otkl)) {
        a[i][j] = 'D';
        cout << a[i][j];
      } else {
        a[i][j] = '*';
        cout << a[i][j];
      }
    }
    cout << endl;
    otkl++;
  }
  long long nas = ((n - 1) / 2) - 1;
  for (long long i = nas; i >= 0; i--) {
    for (size_t j = 0; j < n; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
