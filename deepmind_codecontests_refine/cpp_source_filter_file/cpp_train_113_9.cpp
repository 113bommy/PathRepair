#include <bits/stdc++.h>
using namespace std;
int main() {
  int res1, res2;
  int curra = 0, currb = 0;
  int g;
  cout << "?"
       << " 0"
       << " 0" << endl;
  cout.flush();
  cin >> g;
  for (int i = 1 << 29; i >= 1; i >>= 1) {
    cout << "? " << curra + i << " " << currb << endl;
    cout.flush();
    cin >> res1;
    cout << "? " << curra << " " << currb + i << endl;
    cout.flush();
    cin >> res2;
    if (res1 == 1 && res2 == -1) {
      curra += i;
      currb += i;
    } else if (res1 == res2) {
      if (g == -1)
        curra += i;
      else
        currb += i;
      g = res1;
    }
  }
  cout << "! " << curra << " " << currb << endl;
  cout.flush();
  return 0;
}
