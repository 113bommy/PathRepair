#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e[10], f[10], i, j;
  cin >> a >> b;
  cin >> c >> d;
  for (i = 0; i < 100; i++) {
    e[i] = b + i * a;
    for (j = 0; j < 100; j++) {
      f[j] = d + j * c;
      if (e[i] == f[j]) {
        cout << e[i] << endl;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
