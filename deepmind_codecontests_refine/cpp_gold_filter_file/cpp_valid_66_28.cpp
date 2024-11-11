#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, k[100], a[1667];
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> k[i];
    cout << endl;
  }
  for (int i = 1, j = 1; j <= 1666; j++) {
    if ((j % 3) != 0 && (j % 10) != 3) {
      a[i] = j;
      i++;
    }
  }
  for (int i = 0; i < t; i++) {
    cout << a[k[i]] << endl;
  }
  return 0;
}
