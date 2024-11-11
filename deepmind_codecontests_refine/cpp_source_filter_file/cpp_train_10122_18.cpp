#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int a, b, c = 0;
    cin >> a >> b;
    if (a < b) {
      if ((b - a) % 2)
        c = 2;
      else
        c = 1;
    } else if (a > b) {
      if ((a - b) % 2)
        c = 1;
      else
        c = 2;
    }
    cout << c << endl;
  }
}
