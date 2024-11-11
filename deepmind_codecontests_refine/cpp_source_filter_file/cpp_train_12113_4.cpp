#include <bits/stdc++.h>
using namespace std;
int t, x, a, b, a1, b1;
int main() {
  cin >> x >> t >> a >> b >> a1 >> b1;
  if (x == 0) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i <= t; i++) {
    int curr = b;
    int curr1 = a;
    curr1 -= a1 * i;
    int pok = curr;
    if (curr1 == x) {
      cout << "YES" << endl;
      return 0;
    }
    for (int j = 0; j <= t; j++) {
      curr = pok - b1 * j;
      if (curr == x) {
        cout << "YES" << endl;
        return 0;
      }
      if (curr1 + curr == x) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
