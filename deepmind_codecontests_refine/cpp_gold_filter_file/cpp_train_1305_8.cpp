#include <bits/stdc++.h>
using namespace std;
bool solve(int a, int b, int c) {
  if (c == 0) return a == b;
  int d = b - a;
  if (c < 0) {
    c *= -1;
    d *= -1;
  }
  return d >= 0 && d % c == 0;
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (solve(a, b, c) ? "YES" : "NO") << endl;
}
