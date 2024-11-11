#include <bits/stdc++.h>
using namespace std;
int row, col, a, b, c, d;
bool ans = false;
void check() {
  if (a + c <= col && b <= row && d <= row)
    ans = true;
  else if (b + d <= row && a <= col && d <= col)
    ans = true;
}
int main() {
  cin >> col >> row >> a >> b >> c >> d;
  check();
  int temp = a;
  a = b;
  b = temp;
  check();
  temp = c;
  c = d;
  d = temp;
  check();
  temp = a;
  a = b;
  b = temp;
  check();
  cout << (ans ? "YES" : "NO");
  return 0;
}
