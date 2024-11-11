#include <bits/stdc++.h>
using namespace std;
int main() {
  long double r, h;
  cin >> r >> h;
  int countt = h / r;
  int s = (h - ((int)(h / r) * r)) / (r / 2);
  if (s == 1) {
    countt++;
    long double weight = (countt - 1) * r + r / 2 + (sqrt(3) + 1) * r / 2;
    if (weight > h + r) {
      cout << countt * 2;
    } else {
      countt * 2 + 1;
    }
  } else {
    cout << countt * 2 + 1;
  }
  return 0;
}
