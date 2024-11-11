#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
long long MOD = 998244353;
int main() {
  string s;
  cin >> s;
  bool up = false;
  bool left = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      if (up) {
        cout << "1 3"
             << "\n";
      } else {
        cout << "1 1"
             << "\n";
      }
      up = !up;
    } else {
      if (left) {
        cout << "1 3"
             << "\n";
      } else {
        cout << "3 3"
             << "\n";
      }
      left = !left;
    }
  }
  return 0;
}
