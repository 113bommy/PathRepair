#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, x;
  cin >> a >> b >> c;
  x = min(a, min(b / 2, c / 4));
  cout << x * 7 << endl;
}
