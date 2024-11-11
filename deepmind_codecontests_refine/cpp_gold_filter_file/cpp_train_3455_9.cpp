#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string numero;
  cin >> numero;
  if (k == 0)
    cout << numero << endl;
  else if (n == 1)
    cout << 0 << endl;
  else if (k == n) {
    cout << 1;
    for (int i = 1; i <= n - 1; i++) cout << 0;
    cout << endl;
  } else {
    int krestante = k;
    if (numero[0] != '1' and krestante > 0) {
      numero[0] = '1';
      krestante--;
    }
    for (int i = 1; i < n and krestante > 0; i++) {
      if (numero[i] != '0') {
        numero[i] = '0';
        krestante--;
      }
    }
    cout << numero << endl;
  }
  return 0;
}
