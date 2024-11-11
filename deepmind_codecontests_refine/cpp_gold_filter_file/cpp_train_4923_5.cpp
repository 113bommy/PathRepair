#include <bits/stdc++.h>
using namespace std;
int main() {
  int t{0};
  cin >> t;
  while (t--) {
    string temp;
    int zero{0}, one{0}, n{0}, c0{0}, c1{0}, h{0}, T{0};
    cin >> n >> c0 >> c1 >> h;
    cin >> temp;
    for (auto x : temp) {
      if (x == '0') {
        zero++;
      } else {
        one++;
      }
    }
    if (c1 == c0) {
      T = one * c1 + c0 * (zero);
    } else if (c1 < c0) {
      if (h < (c0 - c1)) {
        T = n * c1 + h * (zero);
      } else {
        T = one * c1 + c0 * (zero);
      }
    } else if (c0 < c1) {
      if (h < (c1 - c0)) {
        T = n * c0 + h * (one);
      } else {
        T = one * c1 + c0 * (zero);
      }
    }
    cout << T << endl;
  }
}
