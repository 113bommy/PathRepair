#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int main() {
  ios_base::sync_with_stdio(false);
  int m, d, ngay;
  cin >> m >> d;
  if (m >= 1 && m <= 7) {
    if (m == 2)
      ngay = 28;
    else if (m % 2 == 0)
      ngay = 30;
    else
      ngay = 31;
  } else {
    if (m % 2 == 0)
      ngay = 31;
    else
      ngay = 30;
  }
  if (ngay == 28) {
    if (d == 1)
      cout << 4 << endl;
    else
      cout << 5 << endl;
  }
  if (ngay == 30) {
    if (d <= 6)
      cout << 5 << endl;
    else
      cout << 6 << endl;
  }
  if (ngay == 31) {
    if (d <= 5)
      cout << 5 << endl;
    else
      cout << 6 << endl;
  }
}
