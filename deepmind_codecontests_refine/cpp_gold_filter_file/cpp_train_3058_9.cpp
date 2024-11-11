#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> a >> b >> n;
  int t = 0;
  for (int i = 0; i <= 9; i++) {
    if ((a * 10 + i) % b == 0) {
      t = 1;
      cout << a * 10 + i;
      for (int j = 0; j < n - 1; j++) {
        cout << "0";
      }
      cout << endl;
      break;
    }
  }
  if (t == 0) {
    cout << "-1" << endl;
  }
}
