#include <bits/stdc++.h>
using namespace std;
int main() {
  string a = "00", b = "11", q;
  int c = 0, d = 0, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> q;
    if (q != a && a == "00") {
      a = q;
      c++;
    } else if (q == a) {
      c++;
    } else if (q == b && b == "11") {
      b = q;
      d++;
    } else {
      d++;
    }
  }
  if (c > d) {
    cout << a;
  } else {
    cout << b;
  }
}
