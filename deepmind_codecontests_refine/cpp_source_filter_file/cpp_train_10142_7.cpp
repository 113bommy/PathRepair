#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c1 = 0, c2 = 0, d = 0;
  cin >> a >> b;
  for (int i = 1; i <= 6; i++) {
    int d1 = abs(a - i), d2 = abs(b - i);
    if (d1 > d2)
      c1++;
    else if (d1 < d2)
      c2++;
    else
      d++;
  }
  cout << c1 << " " << d << " " << c2 << endl;
  return 0;
}
