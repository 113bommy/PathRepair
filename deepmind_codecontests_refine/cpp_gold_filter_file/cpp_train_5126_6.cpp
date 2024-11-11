#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    bool mas[2000] = {};
    int counter = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      mas[k] = true;
      if (k == (counter + 1)) {
        counter++;
      }
    }
    int x1 = 0;
    while (true) {
      if (!mas[counter + 1]) {
        if (x1 == x) break;
        counter++;
        x1++;
      } else {
        counter++;
      }
    }
    cout << counter << endl;
  }
}
