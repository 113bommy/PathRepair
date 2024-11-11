#include <bits/stdc++.h>
using namespace std;
void pp(int x, int y, int n) {
  int c = 0;
  while (1) {
    x += y;
    c++;
    if (x > n) break;
    y += x;
    c++;
    if (y > n) break;
  }
  cout << c << endl;
}
void cc(int x, int y, int n) {
  int c = 0;
  while (1) {
    y += x;
    c++;
    if (y > n) break;
    x += y;
    c++;
    if (x > n) break;
  }
  cout << c << endl;
}
int main() {
  int test, a, b, n;
  cin >> test;
  while (test--) {
    cin >> a >> b >> n;
    if (a >= b)
      cc(a, b, n);
    else if (a < b)
      pp(a, b, n);
  }
  return 0;
}
