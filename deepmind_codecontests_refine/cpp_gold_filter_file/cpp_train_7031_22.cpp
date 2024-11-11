#include <bits/stdc++.h>
using namespace std;
int main() {
  int p1, p2, p3, p4, a, b;
  cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
  int temp1 = min(min(min(p1, p2), p3), p4);
  int temp2 = min(a, b);
  if (max(a, b) >= temp1 && min(a, b) < temp1) {
    if (a == b)
      cout << 1 << '\n';
    else if (max(a, b) != temp1)
      cout << temp1 - temp2 << '\n';
    else if (max(a, b) == temp1)
      cout << temp1 - temp2 - 1 << '\n';
  } else if (max(a, b) <= temp1 && min(a, b) < temp1) {
    if (a == b)
      cout << 1 << '\n';
    else if (max(a, b) != temp1)
      cout << max(a, b) - min(a, b) + 1 << '\n';
    else if (max(a, b) == temp1)
      cout << max(a, b) - min(a, b) << '\n';
    else if (a == b)
      cout << 1 << '\n';
  } else
    cout << 0 << '\n';
  return 0;
}
