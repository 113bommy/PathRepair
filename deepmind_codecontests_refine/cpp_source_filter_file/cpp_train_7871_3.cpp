#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = 0, y = 0, z = 1023;
  for (int i = 1; i <= n; i++) {
    char c;
    int v;
    cin >> c >> v;
    if (c == '&') {
      x &= v;
      y &= v;
      z &= v;
    } else if (c == '|') {
      x |= v;
      int d = (y & 1);
      y ^= d;
    } else
      y ^= v;
  }
  cout << 3 << "\n";
  cout << "& " << z << endl;
  cout << "| " << x << "\n";
  cout << "^ " << y << "\n";
  return 0;
}
