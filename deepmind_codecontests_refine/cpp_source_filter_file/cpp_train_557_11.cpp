#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int s1, s11, s12;
  int s2 = 0;
  s1 = s11 = s12 = 0;
  string s, c;
  s = c = "";
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (i == 0) {
      s1 = a;
      s2 = 0;
      s = "A";
    } else {
      if (abs(s1 + a - s2) < abs(s2 + b - s1)) {
        s1 += a;
        s += "A";
      } else {
        s2 += b;
        s += "G";
      }
    }
    if (i == 0) {
      s11 = a;
      s12 = 0;
      c = "A";
    } else {
      if (abs(s11 + a - s12) < abs(s12 + b - s11)) {
        s11 += a;
        c += "A";
      } else {
        s12 += b;
        c += "G";
      }
    }
  }
  if (abs(s1 - s2) <= 500) {
    cout << s;
    return 0;
  }
  if (abs(s11 - s12) <= 500) {
    cout << c;
    return 0;
  }
  cout << -1;
  return 0;
}
