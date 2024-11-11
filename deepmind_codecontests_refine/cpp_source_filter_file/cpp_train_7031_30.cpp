#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int min1 = min(p1, p2);
  min1 = min(min1, p3);
  min1 = min(min1, p4);
  if (min1 < a)
    cout << 0;
  else if (min1 <= b)
    cout << (min1 - a);
  else
    cout << (min1 - b);
  return 0;
}
