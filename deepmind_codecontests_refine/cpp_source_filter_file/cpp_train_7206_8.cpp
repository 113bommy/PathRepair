#include <bits/stdc++.h>
using namespace std;
int main() {
  int inputs;
  cin >> inputs;
  int a, b, c, d, w, h, area;
  while (inputs--) {
    cin >> a >> b >> c >> d;
    c++;
    d++;
    if (a / 2 < c) {
      w = c - 1;
    } else {
      w = a - c;
    }
    if (b / 2 < d) {
      h = d - 1;
    } else {
      h = b - d;
    }
    if (h > w) {
      area = h * a;
    } else {
      area = w * b;
    }
    cout << area << "\n";
  }
}
