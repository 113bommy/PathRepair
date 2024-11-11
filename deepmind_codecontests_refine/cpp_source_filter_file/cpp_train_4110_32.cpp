#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int res1 = max((3 * a) / 10, (a - (a / 250)) * c);
  int res2 = max((3 * b) / 10, (b - (b / 250)) * d);
  if (res1 > res2)
    cout << "Misha" << endl;
  else if (res1 < res2)
    cout << "Vasya" << endl;
  else
    cout << "Tie" << endl;
  return 0;
}
