#include <bits/stdc++.h>
using namespace std;
int main() {
  string nameOne, nameTwo, tmpOne, tmpTwo;
  cin >> nameOne >> nameTwo;
  int n;
  cin >> n;
  cout << nameOne << " " << nameTwo << endl;
  for (int i = 0; i < n; i++) {
    cin >> tmpOne;
    cin >> tmpTwo;
    if (tmpOne == nameOne)
      nameOne = tmpTwo;
    else
      nameTwo = tmpTwo;
    cout << nameOne << " " << nameTwo << endl;
  }
  return 0;
}
