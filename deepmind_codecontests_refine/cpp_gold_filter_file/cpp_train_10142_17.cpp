#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  int aa = 0, bb = 0, d = 0;
  cin >> a >> b;
  for (int i = 1; i < 7; i++) {
    if (abs(a - i) > abs(b - i)) {
      bb++;
    }
    if (abs(b - i) > abs(a - i)) {
      aa++;
    }
    if (abs(a - i) == abs(b - i)) {
      d++;
    }
  }
  cout << aa << " " << d << " " << bb;
}
