#include <bits/stdc++.h>
using namespace std;
int n;
int low = 0, high;
int valLow;
int getValAt(int x) {
  int vMe, vOther;
  cout << "? " << x + 1 << endl;
  cin >> vMe;
  cout << "? " << x + 1 + n / 2 << endl;
  cin >> vOther;
  return vMe - vOther;
}
int main() {
  cin >> n;
  high = n / 2;
  valLow = getValAt(low);
  if (valLow % 2 != 0) {
    cout << "! " << -1 << endl;
    return 0;
  }
  while (low + 1 != high && valLow != 0) {
    int mid = (low + high) / 2;
    int valMid = getValAt(mid);
    if (valMid == 0)
      low = mid, valLow = valMid;
    else if (valLow < 0 && valMid < 0)
      low = mid, valLow = valMid;
    else if (valLow < 0 && valMid > 0)
      high = mid;
    else if (valLow > 0 && valMid < 0)
      high = mid;
    else if (valLow > 0 && valMid > 0)
      low = mid, valLow = valMid;
    else
      cout << "FAIL" << endl;
  }
  cout << "! " << low + 1 << endl;
  return 0;
}
