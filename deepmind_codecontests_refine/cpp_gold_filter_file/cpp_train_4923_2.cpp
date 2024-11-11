#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, c0, c1, h;
    cin >> n >> c0 >> c1 >> h;
    string s;
    cin >> s;
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        zero++;
      } else {
        one++;
      }
    }
    int cost = zero * c0 + one * c1;
    if (c0 == c1) {
      cout << cost << endl;
    } else if (h >= c0 && h >= c1) {
      cout << cost << endl;
    } else {
      int price = 0;
      if (c0 < c1) {
        if (c1 >= (c0 + h)) {
          price = price + one * h + (zero + one) * c0;
          cout << price << endl;
        } else {
          cout << cost << endl;
        }
      } else {
        if (c0 >= (c1 + h)) {
          price = price + zero * h + (zero + one) * c1;
          cout << price << endl;
        } else {
          cout << cost << endl;
        }
      }
    }
  }
  return 0;
}
