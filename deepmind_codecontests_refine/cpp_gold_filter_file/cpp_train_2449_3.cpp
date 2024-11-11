#include <bits/stdc++.h>
using namespace std;
int main() {
  int al, bl, ar, br;
  cin >> al >> ar >> bl >> br;
  if (br >= (al - 1) && ((al + 1) * 2) >= br) {
    cout << "YES";
    return 0;
  }
  if (bl >= (ar - 1) && ((ar + 1) * 2) >= bl) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}
