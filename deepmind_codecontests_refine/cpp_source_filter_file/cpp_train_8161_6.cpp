#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j;
  cin >> t >> n;
  for (i = 0; i < t; i++) {
    for (j = 0; j < t; j++) {
      if (i == j) {
        cout << t << " ";
      } else {
        cout << "0"
             << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
