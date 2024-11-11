#include <bits/stdc++.h>
using namespace std;
int main() {
  int y, w;
  cin >> y >> w;
  int mx = max(y, w), x = ((6 - mx) + 1);
  if (x / 6 == 1)
    return cout << "1/1" << endl, 0;
  else if (x == 3)
    cout << "1/2" << endl;
  else if (x == 4)
    cout << "2/3" << endl;
  else if (x == 2)
    cout << "1/3" << endl;
  else
    cout << x << "/6" << endl;
  return 0;
}
