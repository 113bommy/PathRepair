#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long x = 1, y = 1;
  while (n--) {
    string str;
    cin >> str;
    if (str == "UL" || str == "DL")
      x++;
    else if (str == "DR" || str == "UR")
      y++;
    else {
      x++;
      y++;
    }
  }
  cout << x * y << endl;
  return 0;
}
