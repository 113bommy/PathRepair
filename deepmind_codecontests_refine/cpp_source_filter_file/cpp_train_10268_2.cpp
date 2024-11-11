#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s[n], g[n];
  for (int i = 0; i < n; i++) cin >> s[i] >> g[i];
  int maximo[n];
  maximo[0] = s[0] + g[0];
  for (int i = 1; i < n; i++) {
    maximo[i] = min(maximo[i - 1] + 1, s[i] + g[i]);
  }
  for (int i = n - 2; i >= 0; i--) {
    maximo[i] = min(maximo[i + 1] + 1, maximo[i]);
  }
  int suma = 0;
  for (int i = 0; i < n; i++) {
    if (maximo[i] < s[i]) {
      cout << -1 << endl;
      return 0;
    }
    suma += maximo[i] - s[i];
  }
  cout << suma << endl;
  for (int i = 0; i < n; i++) cout << maximo[i] << ' ';
}
