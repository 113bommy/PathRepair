#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  int w = 1, h = 1;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    if (s == "UL" || s == "DR")
      h++;
    else if (s == "UR" || s == "DL")
      w++;
    else
      h++, w++;
  }
  cout << h * w << endl;
}
