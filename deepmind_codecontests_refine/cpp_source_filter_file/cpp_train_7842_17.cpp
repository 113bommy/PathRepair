#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int b;
  cin >> b;
  double time;
  cin >> time;
  double initialcount;
  cin >> initialcount;
  bool flag = true;
  double x = 1;
  int w = 0;
  int r = x;
  for (int u = 0; u < time; u++) {
    r = k * r + b;
    if (r >= initialcount) {
      flag = false;
      break;
    }
  }
  double p = initialcount;
  if (flag == false) {
    for (int i = 0; x < initialcount + 1; i++) {
      x = k * x + b;
      w = i;
    }
    double output = 0;
    int y = 0;
    for (int i = 0; p < initialcount + 1; i++) {
      p = k * p + b;
      output = i + 1;
      y = i;
    }
    int m = w - y;
    int t = time - m;
    cout << t << endl;
  } else {
    cout << "0" << endl;
  }
}
