#include <bits/stdc++.h>
using namespace std;
int a, b, aa, bb, cc;
int main() {
  cin >> a >> b;
  for (int i = 1; i <= 6; i++) {
    if (abs(i - a) > abs(i - b))
      aa++;
    else if (abs(i - a) < abs(i - b))
      bb++;
    else if (abs(i - a) == abs(i - b))
      cc++;
  }
  cout << aa << " " << cc << " " << bb;
}
