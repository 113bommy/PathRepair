#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i, j, d;
  cin >> a >> b >> c;
  d = c / 4;
  b = b / 2;
  cout << min(a, min(b, d)) * 7;
  return 0;
}
