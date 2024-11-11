#include <bits/stdc++.h>
using namespace std;
int main() {
  string arr;
  cin >> arr;
  double h = (arr[0] - 48) * 10 + (arr[1] - 48);
  double m = (arr[3] - 48) * 10 + (arr[4] - 48);
  double angh, angm;
  if (h >= 12) h -= 12;
  angh = (30 * h) + (m / 2);
  angm = m * 6;
  cout << angh << " " << angm << endl;
  return 0;
}
