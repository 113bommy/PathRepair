#include <bits/stdc++.h>
using namespace std;
int main() {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int p = min(p1, min(p2, min(p3, p4)));
  if (p <= b) {
    if (p - a > 0)
      cout << p - a;
    else
      cout << 0;
  } else
    cout << b - a + 1;
  return 0;
}
