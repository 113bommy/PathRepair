#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, h, val;
  cin >> r >> h;
  if (h == r) {
    cout << 3;
    return 0;
  }
  val = h / r * 2;
  if (h % r > 0.8 * r)
    val += 3;
  else if (h % r >= (double)r / 2) {
    val += 2;
  } else
    val += 1;
  cout << val;
  return 0;
}
