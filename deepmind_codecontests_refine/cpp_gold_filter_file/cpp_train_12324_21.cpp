#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p = 0;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if ((s.at(0) == 'X' && s.at(1) == '+' && s.at(2) == '+') ||
        (s.at(0) == '+' && s.at(1) == '+' && s.at(2) == 'X')) {
      p = p + 1;
    }
    if ((s.at(0) == 'X' && s.at(1) == '-' && s.at(2) == '-') ||
        (s.at(0) == '-' && s.at(1) == '-' && s.at(2) == 'X')) {
      p = p - 1;
    }
  }
  cout << p << endl;
  return 0;
}
