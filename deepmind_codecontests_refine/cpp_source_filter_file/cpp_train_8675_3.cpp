#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 1, b = 1;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s == "UR" || s == "DL")
      a++;
    else if (s == "UL" || s == "DR")
      b++;
    else {
      a++;
      b++;
    }
  }
  cout << a * b << "\n";
}
